
#ifndef INGAMESTAGE_H
#define INGAMESTAGE_H

#include "framework/stage.h"

struct ComputingCubes;
struct GLTexture;

struct IngameStage : Stage
{
	IngameStage (ComputingCubes *app);
	~IngameStage ();
	
	void update ();
	void draw_scene ();
	
	ComputingCubes *app;
	GLTexture *testtex;
};

#endif // INGAMESTAGE_H

