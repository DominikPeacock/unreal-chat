// Copyright, Dominik Peacock. All rights reserved.

#include "ChatController.h"

#include "Logging.h"
#include "SChatWidget.h"

#define LOCTEXT_NAMESPACE "FChatManagerModule"

FChatController::FChatController(const FString& InChatName)
	:
	ChatName(InChatName),
	TabGuid(FGuid::NewGuid())
{
	auto Tabmanager = FGlobalTabmanager::Get();
	if(Tabmanager->HasTabSpawner(GetTabIdAsName()))
	{
		UE_LOG(ChatManager, Warning, TEXT("FChatController::FChatController: TabSpawner %s is already registered. Overwriting..."), *ChatName);
	}
	
	Tabmanager->RegisterNomadTabSpawner(
		GetTabIdAsName(),
		FOnSpawnTab::CreateRaw(this, &FChatController::CreateOrGetChatTab),
		FCanSpawnTab::CreateLambda([](const FSpawnTabArgs& Args)
		{
				return true;
		})
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

TSharedRef<SDockTab> FChatController::CreateOrGetChatTab(const FSpawnTabArgs& Args)
{
	TSharedRef<SDockTab> CreatedTab = SNew(SDockTab)
		.Label(FText::FromString(ChatName))
		.TabRole(NomadTab)
		.OnTabClosed(SDockTab::FOnTabClosedCallback::CreateRaw(this, &FChatController::OnTabClosed))
	[
		SAssignNew(ChatWidget, SChatWidget)
	];

	return CreatedTab;
}

FName FChatController::GetTabIdAsName() const
{
	return FName(TabGuid.ToString());
}

void FChatController::OnTabClosed(TSharedRef<SDockTab> ClosedTab)
{
	ChatWidget = nullptr;
}

#undef LOCTEXT_NAMESPACE