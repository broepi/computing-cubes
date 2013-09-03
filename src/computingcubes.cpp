
#include <iostream>
#include <sstream>
#include "computingcubes.h"
#include "ingamestage.h"
#include "framework/opengl/gltexture.h"
#include "framework/opengl/gldisplay.h"
#include "framework/opengl/glfont.h"

using namespace std;

ComputingCubes::ComputingCubes ()
	: GLApplication ()
{
	ubuntuMonoFont = new GLFont ("fonts/UbuntuMono-R.ttf", 16);
	curStage = new IngameStage (this);
}

ComputingCubes::~ComputingCubes ()
{
}
