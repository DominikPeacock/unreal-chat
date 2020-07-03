// Copyright, Dominik Peacock. All rights reserved.

#include "SChatWidget.h"

#define LOCTEXT_NAMESPACE "FChatManagerModule"

void SChatWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
		[
			SNew(SBorder)
			.Padding(18)
			.BorderImage(FEditorStyle::GetBrush("Docking.Tab.ContentAreaBrush"))
		];
}

#undef LOCTEXT_NAMESPACE