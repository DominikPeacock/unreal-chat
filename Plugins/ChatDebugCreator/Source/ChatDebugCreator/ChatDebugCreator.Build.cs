// Copyright, Dominik Peacock. All rights reserved.

using UnrealBuildTool;

public class ChatDebugCreator : ModuleRules
{
	public ChatDebugCreator(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// Engine modules ...
				"CoreUObject",
				"Engine",

				// Custom modules ...
                "ChatManager"
			}
			);
	}
}
