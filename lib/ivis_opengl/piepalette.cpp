/*
	This file is part of Warzone 2100.
	Copyright (C) 1999-2004  Eidos Interactive
	Copyright (C) 2005-2020  Warzone 2100 Project

	Warzone 2100 is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	Warzone 2100 is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Warzone 2100; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/
#include "lib/framework/frame.h"
#include "lib/framework/file.h"
#include "lib/ivis_opengl/piestate.h"
#include "lib/ivis_opengl/piepalette.h"
#include "screen.h"

PIELIGHT psPalette[WZCOL_MAX];

void pal_Init()
{
	char *pFileData = nullptr;
	UDWORD fileSize = 0;

	// Read these from file so that mod-makers can change them
	if (loadFile("palette.txt", &pFileData, &fileSize))
	{
		char * ptr = pFileData;
		int lenLeft = fileSize;
		for (int i = 0; i < WZCOL_MAX; i++)
		{
			if (lenLeft <= 0)
			{
				// No more data to read - palette.txt is likely for an older version of WZ
				debug(LOG_FATAL, "palette.txt is missing required value(s); (missing lines %d - %d)", i, (WZCOL_MAX-1));
				return;
			}

			unsigned int r, g, b, a;
			int len;

			int result = sscanf(ptr, "%x, %x, %x, %x %*[^\n]\n%n", &r, &g, &b, &a, &len);

			ptr += len;
			lenLeft -= len;
			ASSERT(lenLeft >= 0, "Buffer overrun reading palette data");

			if (result != 4)
			{
				debug(LOG_ERROR, "Truncated / invalid line (%d) in palette.txt only has %d valid values", (i + 1), result);
				continue;
			}
			psPalette[i].byte.r = r;
			psPalette[i].byte.g = g;
			psPalette[i].byte.b = b;
			psPalette[i].byte.a = a;
		}
		free(pFileData);
	}
	else
	{
		debug(LOG_FATAL, "Failed to load palette.txt");
	}
}

void pal_ShutDown()
{
	// placeholder
}

PIELIGHT pal_GetTeamColour(int team)
{
	PIELIGHT tcolour;

	// set correct team colour based on team
	switch (team)
	{
	case 0:
		tcolour = WZCOL_TEAM1; //green
		break;
	case 1:
		tcolour = WZCOL_TEAM2; //orange
		break;
	case 2:
		tcolour = WZCOL_TEAM3; //gray
		break;
	case 3:
		tcolour = WZCOL_TEAM4; //black
		break;
	case 4:
		tcolour = WZCOL_TEAM5; //red
		break;
	case 5:
		tcolour = WZCOL_TEAM6; //blue
		break;
	case 6:
		tcolour = WZCOL_TEAM7; //purple
		break;
	case 7:
		tcolour = WZCOL_TEAM8; //teal
		break;
	case  8: return WZCOL_TEAM9;
	case  9: return WZCOL_TEAM10;
	case 10: return WZCOL_TEAM11;
	case 11: return WZCOL_TEAM12;
	case 12: return WZCOL_TEAM13;
	case 13: return WZCOL_TEAM14;
	case 14: return WZCOL_TEAM15;
	case 15: return WZCOL_TEAM16;
	default:
		tcolour = WZCOL_WHITE; //default is white
		break;
	}

	return tcolour;
}
