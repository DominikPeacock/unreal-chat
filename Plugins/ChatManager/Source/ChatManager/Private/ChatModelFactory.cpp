// Copyright, Dominik Peacock. All rights reserved.

#include "ChatModelFactory.h"

#include "MessagingChatModel.h"

TSharedRef<IChatModel> FChatModelFactory::CreateMessageBusChat(const FString& ChatName, const FString& SenderName, const FName& MessagingChannelName)
{
	return TSharedRef<IChatModel>(new FMessagingChatModel(ChatName, SenderName, MessagingChannelName));
}