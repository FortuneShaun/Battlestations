//Copyright Fortune Studios 2015. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class BattlestationsTarget : TargetRules
{
	public BattlestationsTarget(TargetInfo Target)
	{
		Type = TargetType.Game;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "Battlestations" } );
	}
}
