
/*

    Computing Cubes
    Copyright (C) 2013  broepi <broepi@broepi.de>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/


#ifndef INGAMESTAGE_H
#define INGAMESTAGE_H

#include "framework/eventmanager.h"
#include "framework/stage.h"
#include "world/chunkmap.h"

struct ComputingCubes;
struct GLTexture;
struct GLCoordAxis;
struct FirstPersonCamera;
struct ChunkMap;
struct WireCube;
struct CrossHairs;

struct IngameStage : Stage, EventManager::Handler
{
	IngameStage (ComputingCubes *app);
	~IngameStage ();
	
	void update ();
	void drawScene ();
	void onEvent (SDL_Event *event);
	
	ComputingCubes *app;
	GLCoordAxis *axis;
	FirstPersonCamera *playerCam;
	WireCube *picker;
	CrossHairs *cross;
	ChunkMap::HitRecord faceHit;
	
	float rightSpeed, leftSpeed, upSpeed, downSpeed, fwdSpeed, backSpeed;
	bool mouseCaught;
	
	ChunkMap *cm;
	
	// Textures
	GLTexture *terrainTex;
	GLTexture *logoTex;
};

#endif // INGAMESTAGE_H

