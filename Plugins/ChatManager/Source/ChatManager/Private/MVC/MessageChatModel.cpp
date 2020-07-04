// Copyright, Dominik Peacock. All rights reserved.

#include "MessagingChatModel.h"

#include "Logging.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"

FMessagingChatModel::FMessagingChatModel(const FString& InChatName, const FString& InSenderName, const FName& InMessageChannelName)
	:
	ChatName(InChatName),
	SenderName(InSenderName)
{
	MessageBus = FMessageEndpoint::Builder(InMessageChannelName)
		.Handling<FChatMessage>(this, &FMessagingChatModel::OnReceiveChatMessage)
		.Build();
	if(MessageBus.IsValid())
	{
		MessageBus->Subscribe<FChatMessage>();
	}
	else
	{
		UE_LOG(ChatManager, Warning, TEXT("FMessagingChatModel::FMessagingChatModel: Failed to init message channel %s"), *InMessageChannelName.ToString());
	}
}

FDelegateHandle FMessagingChatModel::AddMessageReceivedCallback(FOnMessageReceivedCallback OnMessageReceivedCallback)
{
	return MessageReceivedEvent.Add(OnMessageReceivedCallback);
}

void FMessagingChatModel::RemoveMessageReceivedCallback(FDelegateHandle CallbackToRemove)
{
	MessageReceivedEvent.Remove(CallbackToRemove);
}

void FMessagingChatModel::SendMessage(const FString& MessageContent)
{
	// Is this a memory leak?
	// Other locations in engine also just "new" the event but I found no spot where it's freed again
	MessageBus->Publish<FChatMessage>(
		new FChatMessage(MessageContent, GetSenderName())
		);
}

FString FMessagingChatModel::GetChatName() const
{
	return ChatName;
}

FString FMessagingChatModel::GetSenderName() const
{
	return SenderName;
}

void FMessagingChatModel::OnReceiveChatMessage(
	const FChatMessage& ChatMessage, 
	const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if(MessageReceivedEvent.IsBound())
	{
		MessageReceivedEvent.Broadcast(ChatMessage);
	}
}