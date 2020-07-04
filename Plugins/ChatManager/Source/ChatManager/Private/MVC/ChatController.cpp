// Copyright, Dominik Peacock. All rights reserved.

#include "ChatController.h"

#include "IChatModel.h"
#include "Logging.h"
#include "SChatWidget.h"

#define LOCTEXT_NAMESPACE "FChatManagerModule"

FChatController::FChatController(TSharedRef<IChatModel> InChatToControl)
	:
	ControlledChat(InChatToControl),
	TabGuid(FGuid::NewGuid())
{
	auto Tabmanager = FGlobalTabmanager::Get();
	Tabmanager->RegisterNomadTabSpawner(
		GetTabIdAsName(),
		FOnSpawnTab::CreateRaw(this, &FChatController::CreateOrGetChatTab),
		FCanSpawnTab::CreateLambda([](const FSpawnTabArgs& Args)
		{
				return true;
		})
	);

	ControlledChat->AddMessageReceivedCallback(
		IChatModel::FOnMessageReceivedCallback::CreateRaw(this, &FChatController::OnModelReceiveChatMessage)
	);
}

FChatController::~FChatController()
{
	auto Tabmanager = FGlobalTabmanager::Get();
	Tabmanager->UnregisterNomadTabSpawner(GetTabIdAsName());
}

void FChatController::OpenChat() const
{
	auto Tabmanager = FGlobalTabmanager::Get();
	Tabmanager->InvokeTab(GetTabIdAsName());
}

TSharedRef<IChatModel> FChatController::GetControlledChat() const
{
	return ControlledChat;
}

FText FChatController::GetMenuLabel() const
{
	return FText::FromString(GetControlledChat()->GetChatName());
}

FText FChatController::GetMenuDescription() const
{
	return FText::FromString(FString("Open ") + GetControlledChat()->GetChatName());
}

TSharedRef<SDockTab> FChatController::CreateOrGetChatTab(const FSpawnTabArgs& Args)
{
	TSharedRef<SDockTab> CreatedTab = SNew(SDockTab)
		.Label(FText::FromString(ControlledChat->GetChatName()))
		.TabRole(NomadTab)
		.OnTabClosed(SDockTab::FOnTabClosedCallback::CreateRaw(this, &FChatController::OnTabClosed))
	[
		SAssignNew(ChatWidget, SChatWidget)
			.OnSendMessageCallback(SChatWidget::FOnSendMessage::CreateRaw(this, &FChatController::OnWidgetSendChatMessage))
	];
	
	return CreatedTab;
}

void FChatController::OnTabClosed(TSharedRef<SDockTab> ClosedTab)
{
	ChatWidget = nullptr;
}

void FChatController::OnModelReceiveChatMessage(const FChatMessage& ChatMessage) const
{
	if(ChatWidget.IsValid())
	{
		ChatWidget->EnqueueNewMessage(
			ChatMessage, 
			ControlledChat->GetChatName().Equals(ChatMessage.SenderName)
		);
	}
}

void FChatController::OnWidgetSendChatMessage(const FString& MessageContent) const
{
	ControlledChat->SendMessage(MessageContent);
}

FName FChatController::GetTabIdAsName() const
{
	return FName(TabGuid.ToString());
}



#undef LOCTEXT_NAMESPACE