// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class POLAR_BEAR : ModuleRules
{
	public POLAR_BEAR(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","CharacterAI","AIModule", "EnhancedInput" });
	}
}
