// Copyright, Dominik Peacock. All rights reserved.

#pragma once

#include "IChatModel.h"

/**
 * Implements chat using the Messaging module.
 */
class FMessagingChatModel : public IChatModel
{
public:

	// TODO: Hook up to Messaging model
    FMessagingChatModel(const FString& InChatName, const FString& InSenderName, const FName& InMessageChannelName);

	//~ Begin IChatModel interface
    FDelegateHandle AddMessageReceivedCallback(FOnMessageReceivedCallback OnMessageReceivedCallback) override;
    void RemoveMessageReceivedCallback(FDelegateHandle CallbackToRemove) override;
    void SendMessage(const FString& MessageContent) override;
	
    FString GetChatName() const override;
    FString GetSenderName() const override;
    const TArray<FChatMessage>& GetChatHistory() const override;
    //~ End IChatModel interface

private:

    void OnReceiveChatMessage(const FChatMessage& ChatMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	
    const FString ChatName;
    const FString SenderName;
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> MessageBus;
    TArray<FChatMessage> ChatHistory;

    FOnMessageReceived MessageReceivedEvent;
	
};
