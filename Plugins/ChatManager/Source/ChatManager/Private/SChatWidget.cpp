// Copyright, Dominik Peacock. All rights reserved.

#include "SChatWidget.h"

#include "Widgets/Layout/SScrollBox.h"

#define LOCTEXT_NAMESPACE "FChatManagerModule"

void SChatWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
		[
			SNew(SBorder)
				.Padding(FMargin(5.f, 5.f, 5.f, 7.f))
				.BorderImage(FEditorStyle::GetBrush("Docking.Tab.ContentAreaBrush"))
			[
				SNew(SVerticalBox)

				// Chat history
				+SVerticalBox::Slot()
					.VAlign(VAlign_Fill)
					.HAlign(HAlign_Fill)
					.FillHeight(1)
					.Padding(FMargin(0.0f, 0.0f, 0.0f, 5.0f))
				[
					SNew(SBorder)
						.BorderImage(FEditorStyle::GetBrush("DetailsView.CategoryTop"))
						.BorderBackgroundColor(FLinearColor(0.5f, 0.5f, 0.5f, 1.0f))
					[
						SNew(SScrollBox)

						// Chat history content
						+SScrollBox::Slot()
							.VAlign(VAlign_Fill)
							.HAlign(HAlign_Fill)
						[
							SAssignNew(ChatHistory, SVerticalBox)
						]
					]
				]

				// Message box and send button
				+SVerticalBox::Slot()
					.VAlign(VAlign_Center)
					.HAlign(HAlign_Fill)
					.AutoHeight()
				[
					SNew(SHorizontalBox)

					// Enter message box
					+SHorizontalBox::Slot()
						.VAlign(VAlign_Center)
						.HAlign(HAlign_Fill)
						.FillWidth(1)
						.Padding(1.f)
					[
						SAssignNew(EnteredMessageBox, SEditableTextBox)
					]

					// Send button
					+SHorizontalBox::Slot()
						.VAlign(VAlign_Center)
						.HAlign(HAlign_Right)
						.AutoWidth()
						.Padding(1.f)
					[
						SNew(SButton)
							.OnClicked(FOnClicked::CreateRaw(this, &SChatWidget::OnClickSend))
						[
							SNew(STextBlock)
							.Text(LOCTEXT("SChatWidget_Send", "Send"))
						]
					]
				]
			]
		];
}

FReply SChatWidget::OnClickSend()
{

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE