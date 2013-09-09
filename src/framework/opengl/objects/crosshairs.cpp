
#include <SDL2/SDL_opengl.h>
#include "framework/opengl/objects/crosshairs.h"
#include "framework/utils.h"

CrossHairs::CrossHairs ()
{
}

CrossHairs::~CrossHairs ()
{
}

void CrossHairs::draw ()
{
	int lineWidth = 2;
	int width = 11;
	int halfWidth = width / 2.0;
	glDisable (GL_TEXTURE_2D);
	glLineWidth (lineWidth);
	glColor3d (1.0, 1.0, 1.0);
	glBegin (GL_LINES);
	glVertex3d (-halfWidth, 0, 0);
	glVertex3d (-halfWidth + width, 0, 0);
	glVertex3d (1, -halfWidth + width, 0);
	glVertex3d (1, -halfWidth, 0);
	glEnd ();
}
