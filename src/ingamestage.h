
#ifndef INGAMESTAGE_H
#define INGAMESTAGE_H

#include "framework/eventmanager.h"
#include "framework/stage.h"

struct ComputingCubes;
struct GLTexture;
struct GLCoordAxis;
struct FirstPersonCamera;
struct ChunkMap;

struct IngameStage : Stage, EventManager::Handler
{
	IngameStage (ComputingCubes *app);
	~IngameStage ();
	
	void update ();
	void drawScene ();
	void onEvent (SDL_Event *event);
	
	ComputingCubes *app;
	GLTexture *testTex;
	GLCoordAxis *axis;
	FirstPersonCamera *playerCam;
	
	float rightSpeed, leftSpeed, upSpeed, downSpeed, fwdSpeed, backSpeed;
	bool mouseCaught;
	
	ChunkMap *cm;
	
	// Textures
	GLTexture *terrainTex;
};

#endif // INGAMESTAGE_H

