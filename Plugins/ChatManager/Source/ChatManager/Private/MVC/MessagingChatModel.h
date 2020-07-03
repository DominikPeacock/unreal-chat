// Copyright, Dominik Peacock. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "IChatModel.h"

/**
 * Implements chat using the Messaging module.
 */
class FMessagingChatModel : public IChatModel
{
public:

	// TODO: Hook up to Messaging model
    FMessagingChatModel(const FString& InChatName);

	//~ Begin IChatModel interface
    FString GetChatName() const override;
    //~ End IChatModel interface

private:

    const FString ChatName;
	
};
