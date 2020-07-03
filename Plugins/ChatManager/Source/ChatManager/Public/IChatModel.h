// Copyright, Dominik Peacock. All rights reserved.

#pragma once

#include "CoreMinimal.h"

class CHATMANAGER_API IChatModel
{
public:


	virtual FString GetChatName() const = 0;


public:

	virtual ~IChatModel() = default;
	
};