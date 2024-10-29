// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TP_TrouNoir : ModuleRules
{
	public TP_TrouNoir(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Niagara" });
	}
}