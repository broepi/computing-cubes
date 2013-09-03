
#ifndef INGAMESTAGE_H
#define INGAMESTAGE_H

#include "framework/stage.h"

struct ComputingCubes;
struct GLTexture;
struct GLCoordAxis;
struct FirstPersonCamera;

struct IngameStage : Stage
{
	IngameStage (ComputingCubes *app);
	~IngameStage ();
	
	void update ();
	void drawScene ();
	
	ComputingCubes *app;
	GLTexture *testTex;
	GLCoordAxis *axis;
	FirstPersonCamera *playerCam;
	
	// Textures
	GLTexture *terrainTex;
};

#endif // INGAMESTAGE_H

