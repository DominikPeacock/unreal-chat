// Copyright, Dominik Peacock. All rights reserved.

#pragma once

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class IChatModel;

class IChatManagerModule : public IModuleInterface
{
public:

	static IChatManagerModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IChatManagerModule>("ChatManager");
	}

	virtual void AddChat(TSharedRef<IChatModel> ChatToAdd) = 0;
	virtual void RemoveChat(TSharedRef<IChatModel> ChatToRemove) = 0;
	
};