// Copyright, Dominik Peacock. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FChatController;

class FChatManagerModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
private:

	void RegisterToolbarComboButton();
	void CreateToolbarComboButton(FToolBarBuilder& ToolbarBuilder);
	TSharedRef<SWidget> MakeChatSelectionMenu();

	TArray<TSharedRef<FChatController>> ActiveChats;
	
};
