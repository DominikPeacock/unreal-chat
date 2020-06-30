// Copyright Epic Games, Inc. All Rights Reserved.

#include "ChatManagerCommands.h"

#define LOCTEXT_NAMESPACE "FChatManagerModule"

void FChatManagerCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "ChatManager", "Execute ChatManager action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
