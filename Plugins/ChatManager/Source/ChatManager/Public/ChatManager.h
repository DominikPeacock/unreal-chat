// Copyright, Dominik Peacock. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FChatManagerModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
	void PluginButtonClicked();
	
private:

	void RegisterToolbarComboButton();
	void CreateToolbarComboButton(FToolBarBuilder& ToolbarBuilder);
	TSharedRef<SWidget> MakeChatSelectionMenu();

private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
