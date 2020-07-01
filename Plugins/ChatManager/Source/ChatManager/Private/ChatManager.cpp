// Copyright Epic Games, Inc. All Rights Reserved.

#include "ChatManager.h"

#include "ChatManagerStyle.h"
#include "Logging.h"

#include "ToolMenus.h"
#include "LevelEditor.h"

static const FName ChatManagerTabName("ChatManager");

#define LOCTEXT_NAMESPACE "FChatManagerModule"

void FChatManagerModule::StartupModule()
{
	FChatManagerStyle::Initialize();
	FChatManagerStyle::ReloadTextures();

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FChatManagerModule::RegisterToolbarComboButton));
}

void FChatManagerModule::ShutdownModule()
{
	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FChatManagerStyle::Shutdown();
}

void FChatManagerModule::RegisterToolbarComboButton()
{
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	TSharedRef<FExtender> ChatMenuExtender(new FExtender());
	ChatMenuExtender->AddToolBarExtension(
		"Settings",
		EExtensionHook::After,
		nullptr,
		FToolBarExtensionDelegate::CreateRaw(this, &FChatManagerModule::CreateToolbarComboButton));
	
	LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ChatMenuExtender);
}

void FChatManagerModule::CreateToolbarComboButton(FToolBarBuilder& ToolbarBuilder)
{
	ToolbarBuilder.AddComboButton(
		FUIAction(),
		FOnGetContent::CreateRaw(this, &FChatManagerModule::MakeChatSelectionMenu),
		LOCTEXT("TestChatManagerChatMenu", "Chat"),
		FText()
	);
}

TSharedRef<SWidget> FChatManagerModule::MakeChatSelectionMenu()
{
	FMenuBuilder MenuBuilder(false, nullptr);

	MenuBuilder.BeginSection("Chats", LOCTEXT("ChatsSection", "Chats"));

	// TODO: Replace this with a dynamic list
	MenuBuilder.AddMenuEntry(
		LOCTEXT("TestChatLabel", "Chat 1"),
		LOCTEXT("TestChatTooltip", "Opens chat 1"),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateLambda([=] 
				{
					UE_LOG(ChatManager, Warning, TEXT("Dummy implementation for chat 1"))
				})
		),
		NAME_None,
		EUserInterfaceActionType::Button
	);
	
	MenuBuilder.EndSection();
	
	return MenuBuilder.MakeWidget();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FChatManagerModule, ChatManager)