// Copyright, Dominik Peacock. All rights reserved.

#pragma once

#include "IChatManagerModule.h"

class FToolBarBuilder;
class FMenuBuilder;

class FChatController;

class FChatManagerModule : public IChatManagerModule
{
public:

	/** IModuleInterface implementation */
	void StartupModule() override;
	void ShutdownModule() override;

	void AddChat(TSharedRef<IChatModel> ChatToAdd) override;
	void RemoveChat(TSharedRef<IChatModel> ChatToRemove) override;
	
private:

	void RegisterToolbarComboButton();
	void CreateToolbarComboButton(FToolBarBuilder& ToolbarBuilder);
	TSharedRef<SWidget> MakeChatSelectionMenu();

	TArray<TSharedRef<FChatController>> ActiveChats;
	
};
