// Copyright, Dominik Peacock. All rights reserved.

#pragma once

struct FChatMessage;

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

	// Interface for ChatManager module
	void OpenChat() const;
	TSharedRef<IChatModel> GetControlledChat() const;
	FText GetMenuLabel() const;
	FText GetMenuDescription() const;

private:

	TSharedRef<SDockTab> CreateOrGetChatTab(const FSpawnTabArgs& Args);
	void DisplayChatHistory() const;
	void OnTabClosed(TSharedRef<SDockTab> ClosedTab);

	void OnModelReceiveChatMessage(const FChatMessage& ChatMessage) const;
	void OnWidgetSendChatMessage(const FString& MessageContent) const;
	FName GetTabIdAsName() const;
	bool WasMessageSentBySelf(const FChatMessage& ChatMessage) const;


	// Const members
	const TSharedRef<IChatModel> ControlledChat;
	const FGuid TabGuid;

	// Mutable members
	TSharedPtr<SChatWidget> ChatWidget;
	
};
