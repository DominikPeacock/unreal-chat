// Copyright, Dominik Peacock. All rights reserved.

#pragma once

#include "ChatMessage.h"

class CHATMANAGER_API IChatModel
{
public:

	DECLARE_MULTICAST_DELEGATE_OneParam(FOnMessageReceived, const FChatMessage&);
	typedef FOnMessageReceived::FDelegate FOnMessageReceivedCallback;

	virtual FDelegateHandle AddMessageReceivedCallback(FOnMessageReceivedCallback OnMessageReceivedCallback) = 0;
	virtual void RemoveMessageReceivedCallback(FDelegateHandle CallbackToRemove) = 0;
	virtual void SendMessage(const FString& MessageContent) = 0;
	
	virtual FString GetChatName() const = 0;
	/**
	 * @return The name of the local person sending messages
	 */
	virtual FString GetSenderName() const = 0;

public:

	virtual ~IChatModel() = default;
	
};