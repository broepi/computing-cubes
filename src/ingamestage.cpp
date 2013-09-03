
#include <sstream>
#include "ingamestage.h"
#include "computingcubes.h"
#include "firstpersoncamera.h"
#include "framework/utils.h"
#include "framework/opengl/gltexture.h"
#include "framework/opengl/gldisplay.h"
#include "framework/opengl/glfont.h"
#include "framework/opengl/objects/glcoordaxis.h"

using namespace std;

IngameStage::IngameStage (ComputingCubes *app)
	: app (app)
{
	// load textures
	terrainTex = new GLTexture ("images/terrain.png");
	
	playerCam = new FirstPersonCamera (app->display);
	playerCam->x = 0.5;
	playerCam->y = 0.5;
	playerCam->z = -1.0;
	testTex = new GLTexture ("images/proteus.png");
	axis = new GLCoordAxis ();
}

IngameStage::~IngameStage ()
{	
	delete testTex;
	delete terrainTex;
}

void IngameStage::update ()
{
}

void IngameStage::drawScene ()
{
	app->display->activateWorldDrawMode (playerCam);

	axis->draw ();
	
	app->display->activateScreenDrawMode ();

	testTex->drawEx (10, 60);

	stringstream fpsLabel;
	fpsLabel << "Framerate: " << app->fpsMeasured;
	GLTexture *fpsLabelTex = app->ubuntuMonoFont->renderText (fpsLabel.str(), RGB (0,255,255));
	fpsLabelTex->drawEx (10, 10);
	delete fpsLabelTex;

	GLTexture *label2Tex =
		app->ubuntuMonoFont->renderText ("Some german special letters: ÄÖÜäöüß", RGB (255,255,0));
	label2Tex->drawEx (10, 30);
	delete label2Tex;
}

