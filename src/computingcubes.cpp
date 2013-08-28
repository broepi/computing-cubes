
#include <iostream>
#include "computingcubes.h"
#include "framework/opengl/gltexture.h"
#include "framework/opengl/gldisplay.h"
#include "framework/font.h"

using namespace std;

ComputingCubes::ComputingCubes ()
	: GLApplication ()
{
	testtex = new GLTexture ("images/proteus.png");
	myfont = new Font ("fonts/UbuntuMono-R.ttf", 40);
}

ComputingCubes::~ComputingCubes ()
{
	delete testtex;
}

void ComputingCubes::draw_scene ()
{
	display->toggle_screen_drawmode ();
	//testtex->draw ();
	GLTexture *text = myfont->render_text (string("Hello World!"), RGB (255,255,255,255));
	text->draw ();
	//delete text;
}
