// Copyright, Dominik Peacock. All rights reserved.

#include "SMessageText.h"

#define LOCTEXT_NAMESPACE "FChatManagerModule"

void SMessageText::Construct(const FArguments& InArgs)
{
	const FSlateColor SentByMeColour = FSlateColor(FLinearColor(148.f / 255.f, 0.f, 211.f / 255.f));
	const FSlateColor SentByOtherColour = FSlateColor(FLinearColor(0.f, 139.f / 255.f, 139.f / 255.f));

	const FSlateColor TextColour =
		InArgs._NameDisplayType == SentByMe ? SentByMeColour : SentByOtherColour;
	const FText SenderName = 
		InArgs._NameDisplayType == SentByMe ? LOCTEXT("SentByMe", "Me") : InArgs._SenderName;
	
	ChildSlot
	[
		SNew(SHorizontalBox)

		// Message sender
		+SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0.f, 0.f, 5.f, 0.f)
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
				.Text(SenderName)
				.AutoWrapText(false)
				.ColorAndOpacity(TextColour)
		]

		// Message content
		+SHorizontalBox::Slot()
			.FillWidth(1.f)
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
				.Text(InArgs._MessageContent)
				.AutoWrapText(true)
				.ColorAndOpacity(TextColour)
		]
	];
}

#undef LOCTEXT_NAMESPACE