
#ifndef GLCOORDAXIS_H
#define GLCOORDAXIS_H

#include "framework/opengl/gldrawable.h"

struct GLCoordAxis : GLDrawable
{
	GLCoordAxis ();
	~GLCoordAxis ();
	void draw ();
};

#endif // GLCOORDAXIS_H

