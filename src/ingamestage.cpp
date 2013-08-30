
#include <sstream>
#include "ingamestage.h"
#include "computingcubes.h"
#include "framework/utils.h"
#include "framework/opengl/gltexture.h"
#include "framework/opengl/gldisplay.h"
#include "framework/opengl/glfont.h"

using namespace std;

IngameStage::IngameStage (ComputingCubes *app)
	: app (app)
{
	testtex = new GLTexture ("images/proteus.png");
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
	app->display->toggle_screen_drawmode ();
	testtex->drawx (10, 60);
	stringstream fps_label;
	fps_label << "Framerate: " << app->fps_measured;
	GLTexture *fps_label_tex = app->ubuntumono_font->render_text (fps_label.str(), RGB (0,255,255));
	GLTexture *label2_tex =
		app->ubuntumono_font->render_text ("Some german special letters: ÄÖÜäöüß", RGB (255,255,0));
	fps_label_tex->drawx (10, 10);
	label2_tex->drawx (10, 30);
	delete fps_label_tex;
	delete label2_tex;
}
