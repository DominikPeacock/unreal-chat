// Copyright, Dominik Peacock. All rights reserved.

#pragma once

#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"

struct FChatMessage;

class SEditableTextBox;
class SVerticalBox;

class SChatWidget : public SCompoundWidget
{
public:

	DECLARE_DELEGATE_OneParam(FOnSendMessage, const FString&);
	
	SLATE_BEGIN_ARGS(SChatWidget)
	{}
	SLATE_EVENT(FOnSendMessage, OnSendMessageCallback)
	SLATE_END_ARGS()
	void Construct(const FArguments& InArgs);

	void EnqueueNewMessage(const FChatMessage& ChatMessage, bool bIsSentBySelf);
	
private:

	FReply OnClickSend();


	TSharedPtr<SVerticalBox> ChatHistory;
	TSharedPtr<SEditableTextBox> EnteredMessageBox;

	FOnSendMessage OnSendMessageCallback;
	
};