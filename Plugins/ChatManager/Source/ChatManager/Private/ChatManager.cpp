// Copyright, Dominik Peacock. All rights reserved.

#include "ChatManager.h"

#include "ChatController.h"
#include "ChatManagerStyle.h"

#include "ToolMenus.h"
#include "LevelEditor.h"

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

void FChatManagerModule::AddChat(TSharedRef<IChatModel> ChatToAdd)
{
	TSharedRef<FChatController> NewChatController(new FChatController(ChatToAdd));
	ActiveChats.Add(NewChatController);
}

void FChatManagerModule::RemoveChat(TSharedRef<IChatModel> ChatToRemove)
{
	ActiveChats.RemoveAll([=](auto controller)
		{
			return controller->GetControlledChat() == ChatToRemove;
		});
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
	for (auto e : ActiveChats)
	{
		MenuBuilder.AddMenuEntry(
			LOCTEXT("TestChatLabel", "Dummy chat label"),
			LOCTEXT("TestChatTooltip", "Dummy chat description"),
			FSlateIcon(),
			FUIAction(
				FExecuteAction::CreateRaw(&e.Get(), &FChatController::OpenChat)
			),
			NAME_None,
			EUserInterfaceActionType::Button
		);
	}
	MenuBuilder.EndSection();
	
	return MenuBuilder.MakeWidget();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FChatManagerModule, ChatManager)