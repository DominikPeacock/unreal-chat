// Copyright, Dominik Peacock. All rights reserved.

#pragma once

class SChatWidget;

/**
 * Implements Model-View-Controller architecture for chat system.
 */
class FChatController
{
public:

	// TODO: pass in model reference
	FChatController(const FString& InChatName);
	~FChatController();

	void OpenChat() const;

private:

	TSharedRef<SDockTab> CreateOrGetChatTab(const FSpawnTabArgs& Args);
	FName GetTabIdAsName() const;

	void OnTabClosed(TSharedRef<SDockTab> ClosedTab);

	// Const members
	const FString ChatName;

	// Mutable members
	TSharedPtr<SChatWidget> ChatWidget;
	
};
