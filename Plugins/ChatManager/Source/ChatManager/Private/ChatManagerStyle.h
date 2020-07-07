// Copyright, Dominik Peacock. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateStyle.h"

class FChatManagerStyle
{
public:

	static void Initialize();
	static void Shutdown();
	static void ReloadTextures();
	static const ISlateStyle& Get();
	static FName GetStyleSetName();

private:

	static TSharedPtr< class FSlateStyleSet > StyleInstance;

	
	static TSharedRef< class FSlateStyleSet > Create();
	

public:

	// Colours
	static const FName SentByMeColorKey;
	static const FName SentByOtherColorKey;

	// Fonts
	static const FName MessageSenderFontKey;
	static const FName MessageContentFontKey;
	
};