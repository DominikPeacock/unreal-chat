// Copyright, Dominik Peacock. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "ChatMessage.generated.h"

USTRUCT()
struct CHATMANAGER_API FChatMessage
{
	GENERATED_BODY()
public:

	UPROPERTY()
	FString MessageContent;
	UPROPERTY()
	FString SenderName;

	FChatMessage(FString messageContent = "", FString senderName = "")
		: MessageContent(messageContent),
		  SenderName(senderName)
	{}
};