// Copyright QueueBitGames

using UnrealBuildTool;
using System.Collections.Generic;

public class SevenFlowerEditorTarget : TargetRules
{
	public SevenFlowerEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "SevenFlower" } );
	}
}
