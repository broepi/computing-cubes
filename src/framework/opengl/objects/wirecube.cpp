
#include <SDL2/SDL_opengl.h>
#include "framework/opengl/objects/wirecube.h"
#include "framework/utils.h"

WireCube::WireCube ()
{
}

WireCube::~WireCube ()
{
}

void WireCube::draw ()
{
	glDisable (GL_TEXTURE_2D);
	glLineWidth (2);
	glColor3d (1.0, 1.0, 1.0);
	glBegin (GL_LINE_LOOP);
	glVertex3d (-0.5,-0.5,-0.5);
	glVertex3d (+0.5,-0.5,-0.5);
	glVertex3d (+0.5,+0.5,-0.5);
	glVertex3d (-0.5,+0.5,-0.5);
	glVertex3d (-0.5,+0.5,+0.5);
	glVertex3d (+0.5,+0.5,+0.5);
	glVertex3d (+0.5,-0.5,+0.5);
	glVertex3d (-0.5,-0.5,+0.5);
	glEnd ();
	glBegin (GL_LINES);
	glVertex3d (-0.5,-0.5,-0.5);
	glVertex3d (-0.5,+0.5,-0.5);
	glVertex3d (-0.5,-0.5,+0.5);
	glVertex3d (-0.5,+0.5,+0.5);
	glVertex3d (+0.5,-0.5,-0.5);
	glVertex3d (+0.5,-0.5,+0.5);
	glVertex3d (+0.5,+0.5,-0.5);
	glVertex3d (+0.5,+0.5,+0.5);
	glEnd ();
}
