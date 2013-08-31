
#include <SDL2/SDL_opengl.h>
#include "framework/opengl/objects/glcoordaxis.h"
#include "framework/utils.h"

GLCoordAxis::GLCoordAxis ()
{
}

GLCoordAxis::~GLCoordAxis ()
{
}

void GLCoordAxis::draw ()
{
	glDisable (GL_TEXTURE_2D);
	glLineWidth (2);
	glBegin (GL_LINES);
	glColor3d (1,0,0);
	glVertex3d (0,0,0);
	glVertex3d (1,0,0);
	glColor3d (0,1,0);
	glVertex3d (0,0,0);
	glVertex3d (0,1,0);
	glColor3d (0,0,1);
	glVertex3d (0,0,0);
	glVertex3d (0,0,1);
	glEnd ();
}

