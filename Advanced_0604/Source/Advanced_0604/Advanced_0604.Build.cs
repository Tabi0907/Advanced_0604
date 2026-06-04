// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Advanced_0604 : ModuleRules
{
	public Advanced_0604(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
