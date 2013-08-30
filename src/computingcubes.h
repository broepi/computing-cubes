
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
	
	GLFont *ubuntumono_font;
};

#endif // computingcubes_H

