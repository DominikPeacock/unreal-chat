// Copyright, Dominik Peacock. All rights reserved.

#include "ChatManagerStyle.h"

#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"

TSharedPtr< FSlateStyleSet > FChatManagerStyle::StyleInstance = NULL;

const FName FChatManagerStyle::SentByMeColorKey("ChatManager.SentByMeColor");
const FName FChatManagerStyle::SentByOtherColorKey("ChatManager.SentByOtherColor");

const FName FChatManagerStyle::MessageSenderFontKey("ChatManager.MessageSenderFont");
const FName FChatManagerStyle::MessageContentFontKey("ChatManager.MessageContentFont");

void FChatManagerStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FChatManagerStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FChatManagerStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("ChatManager"));
	return StyleSetName;
}

#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BOX_BRUSH( RelativePath, ... ) FSlateBoxBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BORDER_BRUSH( RelativePath, ... ) FSlateBorderBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define TTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".ttf") ), __VA_ARGS__ )
#define OTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".otf") ), __VA_ARGS__ )

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon40x40(40.0f, 40.0f);

TSharedRef< FSlateStyleSet > FChatManagerStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("ChatManager"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("ChatManager")->GetBaseDir() / TEXT("Resources"));

	// Colors
	{
		const FSlateColor SentByMeColor = FSlateColor(FLinearColor(148.f / 255.f, 0.f, 211.f / 255.f));
		const FSlateColor SentByOtherColor = FSlateColor(FLinearColor(0.f, 139.f / 255.f, 139.f / 255.f));

		Style->Set(SentByMeColorKey, SentByMeColor);
		Style->Set(SentByOtherColorKey, SentByOtherColor);
	}

	// Fonts
	{
		auto& CoreStyle = FCoreStyle::Get();
		auto UnderlinedFont = CoreStyle.GetWidgetStyle<FTextBlockStyle>("NormalUnderlinedText");
		auto RegularFont = CoreStyle.GetWidgetStyle<FTextBlockStyle>("NormalText");

		UnderlinedFont.SetFontSize(12);
		RegularFont.SetFontSize(12);
		
		Style->Set(MessageSenderFontKey, UnderlinedFont);
		Style->Set(MessageContentFontKey, RegularFont);
	}

	return Style;
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT

void FChatManagerStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FChatManagerStyle::Get()
{
	return *StyleInstance;
}
