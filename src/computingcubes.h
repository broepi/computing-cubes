
#ifndef computingcubes_H
#define computingcubes_H

#include "framework/opengl/glapplication.h"

struct GLTexture;
struct GLFont;

struct ComputingCubes : GLApplication
{
	ComputingCubes ();
	~ComputingCubes ();
	void drawScene ();
	
	GLFont *ubuntuMonoFont;
};

#endif // computingcubes_H

