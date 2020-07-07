// Copyright, Dominik Peacock. All rights reserved.

#include "SMessageText.h"

#include "ChatManagerStyle.h"

#define LOCTEXT_NAMESPACE "FChatManagerModule"

void SMessageText::Construct(const FArguments& InArgs)
{
	auto& Style = FChatManagerStyle::Get();

	const FSlateColor TextColour =
		InArgs._NameDisplayType == SentByMe ? Style.GetSlateColor(FChatManagerStyle::SentByMeColorKey) : Style.GetSlateColor(FChatManagerStyle::SentByOtherColorKey);
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
			.VAlign(VAlign_Top)
		[
			SNew(STextBlock)
				.AutoWrapText(false)
				.TextStyle(Style, FChatManagerStyle::MessageSenderFontKey)
				.Text(SenderName)
				.ColorAndOpacity(TextColour)
		]

		// Message content
		+SHorizontalBox::Slot()
			.FillWidth(1.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
				.AutoWrapText(true)
				.WrappingPolicy(ETextWrappingPolicy::AllowPerCharacterWrapping)
				.Justification(ETextJustify::Left)
				.Text(InArgs._MessageContent)
				.TextStyle(Style, FChatManagerStyle::MessageContentFontKey)
				.ColorAndOpacity(TextColour)
		]
	];
}

#undef LOCTEXT_NAMESPACE