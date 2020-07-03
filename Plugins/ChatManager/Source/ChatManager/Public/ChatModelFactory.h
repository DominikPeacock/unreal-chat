// Copyright, Dominik Peacock. All rights reserved.

#pragma once

#include "CoreMinimal.h"

class IChatModel;

class CHATMANAGER_API FChatModelFactory
{
public:
	
	/**
	 * Creates a chat uses the Message module for sending messages.
	 */
	static TSharedRef<IChatModel> CreateMessageBusChat(const FString& ChatName);
};