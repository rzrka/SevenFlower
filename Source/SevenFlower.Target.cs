// Copyright QueueBitGames

using UnrealBuildTool;
using System.Collections.Generic;

public class SevenFlowerTarget : TargetRules
{
	public SevenFlowerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "SevenFlower" } );
	}
}
