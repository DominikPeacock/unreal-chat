// Copyright, Dominik Peacock. All rights reserved.

#pragma once

#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"

class SMessageText : public SCompoundWidget
{
public:

	enum ENameDisplayFormat
	{
		SentByMe,
		SentByOtherPerson
	};
	
	SLATE_BEGIN_ARGS(SMessageText)
	{}
	SLATE_ARGUMENT(FText, MessageContent)
	SLATE_ARGUMENT(ENameDisplayFormat, NameDisplayType)
	SLATE_ARGUMENT(FText, SenderName)
	SLATE_END_ARGS()
	
	void Construct(const FArguments& InArgs);
	
};