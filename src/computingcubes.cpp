
#include <iostream>
#include <sstream>
#include "computingcubes.h"
#include "framework/opengl/gltexture.h"
#include "framework/opengl/gldisplay.h"
#include "framework/opengl/glfont.h"

using namespace std;

ComputingCubes::ComputingCubes ()
	: GLApplication ()
{
	testtex = new GLTexture ("images/proteus.png");
	ubuntumono_font = new GLFont ("fonts/UbuntuMono-R.ttf", 16);
}

ComputingCubes::~ComputingCubes ()
{
	delete testtex;
}

void ComputingCubes::draw_scene ()
{
	display->toggle_screen_drawmode ();
	testtex->drawx (10, 60);
	stringstream fps_label;
	fps_label << "Framerate: " << fps_measured;
	GLTexture *fps_label_tex = ubuntumono_font->render_text (fps_label.str(), RGB (0,255,255));
	GLTexture *label2_tex = ubuntumono_font->render_text ("Some german special letters: ÄÖÜäöüß",
		RGB (255,255,0));
	fps_label_tex->drawx (10, 10);
	label2_tex->drawx (10, 30);
	delete fps_label_tex;
}
