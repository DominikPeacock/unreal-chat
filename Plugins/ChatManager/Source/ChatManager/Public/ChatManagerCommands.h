// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "ChatManagerStyle.h"

class FChatManagerCommands : public TCommands<FChatManagerCommands>
{
public:

	FChatManagerCommands()
		: TCommands<FChatManagerCommands>(TEXT("ChatManager"), NSLOCTEXT("Contexts", "ChatManager", "ChatManager Plugin"), NAME_None, FChatManagerStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
