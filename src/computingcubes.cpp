
#include <iostream>
#include "computingcubes.h"
#include "framework/opengl/gltexture.h"
#include "framework/opengl/gldisplay.h"
#include "framework/opengl/glfont.h"

using namespace std;

ComputingCubes::ComputingCubes ()
	: GLApplication ()
{
	testtex = new GLTexture ("images/proteus.png");
	myfont = new GLFont ("fonts/UbuntuMono-R.ttf", 16);
}

ComputingCubes::~ComputingCubes ()
{
	delete testtex;
}

void ComputingCubes::draw_scene ()
{
	display->toggle_screen_drawmode ();
	testtex->draw ();
	GLTexture *text = myfont->render_text ("Hello World! 0123456789", RGB (0,255,255));
	text->draw ();
	delete text;
}
