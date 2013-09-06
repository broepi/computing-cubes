
#include <sstream>
#include <cstdlib>
#include <cmath>
#include "ingamestage.h"
#include "computingcubes.h"
#include "firstpersoncamera.h"
#include "framework/utils.h"
#include "framework/opengl/gltexture.h"
#include "framework/opengl/gldisplay.h"
#include "framework/opengl/glfont.h"
#include "framework/opengl/objects/glcoordaxis.h"
#include "world/chunkmap.h"
#include "world/chunk.h"
#include "world/voxeltypemap.h"

using namespace std;

IngameStage::IngameStage (ComputingCubes *app)
	: app (app)
{
	rightSpeed = 0, leftSpeed = 0, upSpeed = 0, downSpeed = 0, fwdSpeed = 0, backSpeed = 0;
	mouseCaught = false;
	srand (0);
	
	// add handlers
	app->eventManager->addHandler (SDL_KEYDOWN, this);
	app->eventManager->addHandler (SDL_KEYUP, this);
	app->eventManager->addHandler (SDL_MOUSEBUTTONUP, this);
	app->eventManager->addHandler (SDL_MOUSEMOTION, this);
	
	// load textures
	terrainTex = new GLTexture ("images/terrain.png");
	logoTex = new GLTexture ("images/logo.png");
	
	playerCam = new FirstPersonCamera (app->display);
	playerCam->x = 0.5;
	playerCam->y = 0.5;
	playerCam->z = -1.0;
	axis = new GLCoordAxis ();
	
	cm = new ChunkMap (terrainTex);
	Chunk *c = new Chunk ();
	cm->chunks [0] = c;
	for (int i=0; i<FULLCHUNKSIZE; i++)
		c->voxels [i] = rand () % VOXTYPECOUNT;
	c->recreateMesh (0, 0, 0, cm);
}

IngameStage::~IngameStage ()
{	
	delete logoTex;
	delete terrainTex;
}

void IngameStage::update ()
{
}

void IngameStage::drawScene ()
{
	playerCam->x +=
		(fwdSpeed - backSpeed) * sin (degToRad (playerCam->altitude)) +
		(rightSpeed - leftSpeed) * cos (degToRad (playerCam->altitude));
	playerCam->z +=
		(fwdSpeed - backSpeed) * cos (degToRad (playerCam->altitude)) -
		(rightSpeed - leftSpeed) * sin (degToRad (playerCam->altitude));
	playerCam->y += upSpeed - downSpeed;
	
	app->display->activateWorldDrawMode (playerCam);

	cm->draw ();

	glDisable (GL_DEPTH_TEST);
	axis->draw ();
	
	app->display->activateScreenDrawMode ();

	stringstream mystream;
	GLTexture *labelTex;
	
	labelTex = app->ubuntuMonoFont->renderText (
		"\"Computing Cubes\" and some German special letters: äöüÄÖÜß",
		RGB (255,255,255));
	labelTex->drawEx (10, 10);
	delete labelTex;
	
	mystream << "Framerate: " << app->fpsMeasured;
	labelTex = app->ubuntuMonoFont->renderText (mystream.str(), RGB (0,255,255));
	labelTex->drawEx (10, 10 + labelTex->h * 1);
	mystream.str (string());
	delete labelTex;

	mystream << "Position: " << playerCam->x << " ; " << playerCam->y << " ; " << playerCam->z;
	labelTex = app->ubuntuMonoFont->renderText (mystream.str(), RGB (0,255,255));
	labelTex->drawEx (10, 10 + labelTex->h * 2);
	mystream.str (string());
	delete labelTex;
	
	logoTex->drawEx (app->display->w-10-logoTex->w, 10, 0.5);
}

void IngameStage::onEvent (SDL_Event *event)
{
	const float speed = 0.1;
	switch (event->type) {
	case SDL_KEYDOWN:
		switch (event->key.keysym.sym) {
		case SDLK_w:
			fwdSpeed = speed;
			break;
		case SDLK_a:
			leftSpeed = speed;
			break;
		case SDLK_s:
			backSpeed = speed;
			break;
		case SDLK_d:
			rightSpeed = speed;
			break;
		case SDLK_SPACE:
			upSpeed = speed;
			break;
		case SDLK_LSHIFT:
			downSpeed = speed;
			break;
		}
		break;
	case SDL_KEYUP:
		switch (event->key.keysym.sym) {
		case SDLK_w:
			fwdSpeed = 0;
			break;
		case SDLK_a:
			leftSpeed = 0;
			break;
		case SDLK_s:
			backSpeed = 0;
			break;
		case SDLK_d:
			rightSpeed = 0;
			break;
		case SDLK_SPACE:
			upSpeed = 0;
			break;
		case SDLK_LSHIFT:
			downSpeed = 0;
			break;
		}
		break;
	case SDL_MOUSEBUTTONUP:
		if (event->button.button == SDL_BUTTON_LEFT) {
			mouseCaught = !mouseCaught;
			if (mouseCaught)
				SDL_SetRelativeMouseMode (SDL_TRUE);
			else
				SDL_SetRelativeMouseMode (SDL_FALSE);
		}
		break;
	case SDL_MOUSEMOTION:
		if (mouseCaught) {
			playerCam->altitude += event->motion.xrel / (float) app->display->w *2 *90;
			playerCam->azimuth -= event->motion.yrel / (float) app->display->h *2 *90;
			SDL_WarpMouseInWindow (app->display->window, app->display->w/2, app->display->h/2);
		}
		break;
	}
}

