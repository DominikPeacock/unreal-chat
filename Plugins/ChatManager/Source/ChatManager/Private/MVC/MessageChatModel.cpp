// Copyright, Dominik Peacock. All rights reserved.

#include "MessagingChatModel.h"

FMessagingChatModel::FMessagingChatModel(const FString& InChatName)
	:
	ChatName(InChatName)
{}

FString FMessagingChatModel::GetChatName() const
{
	return ChatName;
}