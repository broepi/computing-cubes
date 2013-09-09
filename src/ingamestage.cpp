
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <SDL2/SDL_opengl.h>
#include "ingamestage.h"
#include "computingcubes.h"
#include "firstpersoncamera.h"
#include "framework/utils.h"
#include "framework/opengl/gltexture.h"
#include "framework/opengl/gldisplay.h"
#include "framework/opengl/glfont.h"
#include "framework/opengl/objects/glcoordaxis.h"
#include "framework/opengl/objects/wirecube.h"
#include "framework/opengl/objects/crosshairs.h"
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
	picker = new WireCube ();
	cross = new CrossHairs ();
	
	cm = new ChunkMap (terrainTex);
	for (int x=0; x<16; x++) {
		for (int z=0; z<16; z++) {
			ChunkId k = chunkVectorToId (x,0,z);
			cm->chunks [k] = new Chunk ();
			for (int i=0; i<FULLCHUNKSIZE; i++)
				//cm->chunks [k]->voxels [i] = (i + i/CHUNKSIZE + i/CHUNKSIZE/CHUNKSIZE) % 2;
				cm->chunks [k]->voxels [i] = rand () % VOXTYPECOUNT;
			cm->chunks [k]->recreateMesh (x, 0, z, cm);
		}
	}
	cm->chunks [chunkVectorToId (-1,0,0)] = new Chunk ();
	for (int i=0; i<FULLCHUNKSIZE; i++)
		cm->chunks [chunkVectorToId (-1,0,0)]->voxels [i] = (i + i/CHUNKSIZE + i/CHUNKSIZE/CHUNKSIZE) % 2;
	cm->chunks [chunkVectorToId (-1,0,0)]->recreateMesh (-1, 0, 0, cm);
}

IngameStage::~IngameStage ()
{	
	delete logoTex;
	delete terrainTex;
}

void IngameStage::update ()
{
	cm->hitFirstBlock (playerCam, 10, &faceHit);
	cout << (int)faceHit.face << endl;
}

void IngameStage::drawScene ()
{
	//
	// Camera movement, TODO: shall be done in update()
	//
	playerCam->x +=
		(fwdSpeed - backSpeed) * sin (degToRad (playerCam->altitude)) +
		(rightSpeed - leftSpeed) * cos (degToRad (playerCam->altitude));
	playerCam->z +=
		(fwdSpeed - backSpeed) * cos (degToRad (playerCam->altitude)) -
		(rightSpeed - leftSpeed) * sin (degToRad (playerCam->altitude));
	playerCam->y += upSpeed - downSpeed;
	
	//
	// World drawing
	//
	app->display->activateWorldDrawMode (playerCam);

	cm->draw ();
	
	if (faceHit.face != VOXFACEUNDEF) {
		Sint32 voxCoord[3] = {faceHit.voxelCoord[0], faceHit.voxelCoord[1], faceHit.voxelCoord[2]};
		glPushMatrix ();
		switch (faceHit.face) {
		case VOXFACEFRONT:
			glTranslated (voxCoord[0]+0.5, voxCoord[1]+0.5, voxCoord[2] + 0.0);
			break;
		case VOXFACEBACK:
			glTranslated (voxCoord[0]+0.5, voxCoord[1]+0.5, voxCoord[2] + 1.0);
			break;
		case VOXFACERIGHT:
			glTranslated (voxCoord[0]+1.0, voxCoord[1]+0.5, voxCoord[2] + 0.5);
			glRotatef (90,0,1,0);
			break;
		case VOXFACELEFT:
			glTranslated (voxCoord[0]+0.0, voxCoord[1]+0.5, voxCoord[2] + 0.5);
			glRotatef (90,0,1,0);
			break;
		case VOXFACETOP:
			glTranslated (voxCoord[0]+0.5, voxCoord[1]+1.0, voxCoord[2] + 0.5);
			glRotatef (90,1,0,0);
			break;
		case VOXFACEBOTTOM:
			glTranslated (voxCoord[0]+0.5, voxCoord[1]+0.0, voxCoord[2] + 0.5);
			glRotatef (90,1,0,0);
			break;
		}
		glScaled (1.01, 1.01, 0.02);
		picker->draw ();
		glPopMatrix ();
	}

	glDisable (GL_DEPTH_TEST);
	axis->draw ();
	
	//
	// Screen space drawing
	//
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

	glMatrixMode (GL_MODELVIEW);
	glTranslated (app->display->w / 2.0, app->display->h / 2.0, 0);
	cross->draw ();
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

