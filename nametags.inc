/* Custom Nametags v1.0
 Written by Bork!

 Dependencies:
 - streamer (by incognito)
 - y_hooks (by y_less, apart of YSI)
 - strlib (by slice)
 - foreach (by y_less, apart of YSI (credits go to the contributors as well))

NOTE: These have to be included before you can use nametags, otherwise nametags will include them if it can find them. */

#if defined _inc_NAMETAGS
	#undef _inc_NAMETAGS
#endif
#if defined _NAMETAGS_included
	#endinput
#endif
#define _NAMETAGS_included

#if !defined _samp_included
	#error "a_samp may not be included?"
#endif

#if !defined _streamer_included
	#include <streamer>
#endif

#if !defined STRLIB_INC
	#include <strlib>
#endif

#if !defined _FOREACH_LOCAL_VERSION
	#include <foreach>
#endif

#if !defined NT_DISTANCE
	#define NT_DISTANCE 20.0
#endif

new Text3D:p_Nametag[MAX_PLAYERS];

stock SetPlayerNameTag(playerid, color)
{
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof name);

	p_Nametag[playerid] = CreateDynamic3DTextLabel(sprintf("%s (%d)", name, playerid), color, 0.0, 0.0, 0.1, NT_DISTANCE, .attachedplayer = playerid, .testlos = 1);
	return 1;
}

stock UpdatePlayerNameTag(playerid)
{
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof name);

	UpdateDynamic3DTextLabelText(p_Nametag[playerid], 0xFFFFFFFF, sprintf("{%06x}%s (%d)", GetPlayerColor(playerid) >>> 8, name, playerid));
	return 1;
}

stock DestroyPlayerNameTag(playerid)
{
	if(IsValidDynamic3DTextLabel(p_Nametag[playerid]))
		DestroyDynamic3DTextLabel(p_Nametag[playerid]);
	return 1;
}

#include <YSI\y_hooks>
hook OnGameModeExit()
{
	foreach (new i : Player)
	{
		DestroyPlayerNameTag(i);
	}
	return 1;
}

#include <YSI\y_hooks>
hook OnGameModeInit()
{
	ShowNameTags(false);
	SetNameTagDrawDistance(0.0);
	return 1;
}

#include <YSI\y_hooks>
hook OnPlayerConnect(playerid)
{
	SetPlayerColor(playerid, -1);
	return 1;
}