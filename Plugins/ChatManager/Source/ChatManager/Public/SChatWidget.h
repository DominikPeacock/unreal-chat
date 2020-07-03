// Copyright, Dominik Peacock. All rights reserved.

#pragma once

#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"

class SChatWidget : public SCompoundWidget
{
public:
	
	SLATE_BEGIN_ARGS(SChatWidget)
	{}

	
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:

};