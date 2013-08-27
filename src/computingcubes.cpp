
#include <iostream>
#include "computingcubes.h"
#include "framework/opengl/gltexture.h"

using namespace std;

ComputingCubes::ComputingCubes ()
	: GLApplication ()
{
	testtex = new GLTexture ("images/proteus.png");
}

ComputingCubes::~ComputingCubes ()
{
	delete testtex;
}

void ComputingCubes::draw_scene ()
{
	testtex->draw (display);
}
