
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>
#include "framework/opengl/perspectivecamera.h"
#include "framework/utils.h"

PerspectiveCamera::PerspectiveCamera (Display *display)
	: display (display)
{
	fovy = 90.0;
	znear = 0.1;
	zfar = 100.0;
	lefthanded = true;
}

PerspectiveCamera::~PerspectiveCamera ()
{
}

void PerspectiveCamera::load ()
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (fovy, (float)display->w/display->h, znear, zfar);
	if (lefthanded)
		glScalef (1, 1, -1); // left-handed coordinate system
	
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
}

