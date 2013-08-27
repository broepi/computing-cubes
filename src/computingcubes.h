
#ifndef computingcubes_H
#define computingcubes_H

#include "framework/opengl/glapplication.h"

struct GLTexture;

struct ComputingCubes : GLApplication
{
	ComputingCubes ();
	~ComputingCubes ();
	void draw_scene ();
	
	GLTexture *testtex;
};

#endif // computingcubes_H

