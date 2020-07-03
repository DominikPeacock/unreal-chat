// Copyright, Dominik Peacock. All rights reserved.

#pragma once

class IChatModel;
class SChatWidget;

/**
 * Implements Model-View-Controller architecture for chat system:
 *	- the view is SChatWidget
 *	- the model is IChatModel
 */
class FChatController
{
public:

	FChatController(TSharedRef<IChatModel> InChatToControl);
	~FChatController();

	void OpenChat() const;

	TSharedRef<IChatModel> GetControlledChat() const
	{
		return ControlledChat;
	}

private:

	TSharedRef<SDockTab> CreateOrGetChatTab(const FSpawnTabArgs& Args);
	FName GetTabIdAsName() const;

	void OnTabClosed(TSharedRef<SDockTab> ClosedTab);

	// Const members
	const TSharedRef<IChatModel> ControlledChat;
	const FGuid TabGuid;

	// Mutable members
	TSharedPtr<SChatWidget> ChatWidget;
	
};
