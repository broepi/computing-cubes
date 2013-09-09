
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

