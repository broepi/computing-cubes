
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
	playercam = new FirstPersonCamera (app->display);
	playercam->x = 0.5;
	playercam->y = 0.5;
	playercam->z = -1.0;
	testtex = new GLTexture ("images/proteus.png");
	axis = new GLCoordAxis ();
}

IngameStage::~IngameStage ()
{
	delete testtex;
}

void IngameStage::update ()
{
}

void IngameStage::draw_scene ()
{
	app->display->activate_world_drawmode (playercam);

	axis->draw ();
	
	app->display->activate_screen_drawmode ();

	testtex->drawx (10, 60);

	stringstream fps_label;
	fps_label << "Framerate: " << app->fps_measured;
	GLTexture *fps_label_tex = app->ubuntumono_font->render_text (fps_label.str(), RGB (0,255,255));
	fps_label_tex->drawx (10, 10);
	delete fps_label_tex;

	GLTexture *label2_tex =
		app->ubuntumono_font->render_text ("Some german special letters: ÄÖÜäöüß", RGB (255,255,0));
	label2_tex->drawx (10, 30);
	delete label2_tex;
}

