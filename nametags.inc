/* Custom Nametags v1.0
 Written by Bork!

 Dependencies:
 - streamer (by incognito)
 - y_hooks (by y_less, apart of YSI)

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

#if !defined NT_DISTANCE
	#define NT_DISTANCE 20.0
#endif

new Text3D:p_Nametag[MAX_PLAYERS];

stock SetPlayerNameTag(playerid, color)
{
	new name[MAX_PLAYER_NAME], string[MAX_PLAYER_NAME + 8];
	GetPlayerName(playerid, name, sizeof name);

	format(string, sizeof string, "%s (%d)", name, playerid);

	p_Nametag[playerid] = CreateDynamic3DTextLabel(string, color, 0.0, 0.0, 0.1, NT_DISTANCE, .attachedplayer = playerid, .testlos = 1);
	return 1;
}

stock UpdatePlayerNameTag(playerid)
{
	new name[MAX_PLAYER_NAME], string[MAX_PLAYER_NAME + 20];
	GetPlayerName(playerid, name, sizeof name);

	format(string, sizeof string, "{%06x}%s (%d)", GetPlayerColor(playerid) >>> 8, name, playerid);

	UpdateDynamic3DTextLabelText(p_Nametag[playerid], 0xFFFFFFFF, string);
	return 1;
}

stock DestroyPlayerNameTag(playerid)
{
	if(IsValidDynamic3DTextLabel(p_Nametag[playerid]))
		DestroyDynamic3DTextLabel(p_Nametag[playerid]);

	return 1;
}

#include <YSI\y_hooks>
hook OnGameModeInit()
{
	ShowNameTags(false);
	SetNameTagDrawDistance(0.0);
	return 1;
}

hook OnPlayerConnect(playerid)
{
	SetPlayerColor(playerid, -1);
	return 1;
}
