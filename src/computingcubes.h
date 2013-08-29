
#ifndef computingcubes_H
#define computingcubes_H

#include "framework/opengl/glapplication.h"

struct GLTexture;
struct GLFont;

struct ComputingCubes : GLApplication
{
	ComputingCubes ();
	~ComputingCubes ();
	void draw_scene ();
	
	GLTexture *testtex;
	GLFont *myfont;
};

#endif // computingcubes_H

