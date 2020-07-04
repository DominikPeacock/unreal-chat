// Copyright, Dominik Peacock. All rights reserved.

#include "ChatDebugCreator.h"

#include "ChatModelFactory.h"
#include "IChatModel.h"
#include "IChatManagerModule.h"

#define LOCTEXT_NAMESPACE "FChatDebugCreatorModule"

void FChatDebugCreatorModule::StartupModule()
{
	// Create dummy chats
	auto& ChatManagerModule = IChatManagerModule::Get();

	ChatManagerModule.AddChat(
		FChatModelFactory::CreateMessageBusChat("Chat 1", "Peter", "DummyChannel")
	);
	ChatManagerModule.AddChat(
		FChatModelFactory::CreateMessageBusChat("Chat 2", "Gunther", "DummyChannel")
	);
}

void FChatDebugCreatorModule::ShutdownModule()
{

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FChatDebugCreatorModule, ChatDebugCreator)