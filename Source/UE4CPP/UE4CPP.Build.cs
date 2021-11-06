// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE4CPP : ModuleRules
{
	public UE4CPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
