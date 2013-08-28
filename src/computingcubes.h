
#ifndef computingcubes_H
#define computingcubes_H

#include "framework/opengl/glapplication.h"

struct GLTexture;
struct Font;

struct ComputingCubes : GLApplication
{
	ComputingCubes ();
	~ComputingCubes ();
	void draw_scene ();
	
	GLTexture *testtex;
	Font *myfont;
};

#endif // computingcubes_H

