// Copyright, Dominik Peacock. All rights reserved.

using UnrealBuildTool;

public class ChatManager : ModuleRules
{
	public ChatManager(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "SlateCore"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "CoreUObject",
				"EditorStyle",
                "Engine",
				"Projects",
				"Slate",
				"SlateCore",
                "ToolMenus",
                "UnrealEd"
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
