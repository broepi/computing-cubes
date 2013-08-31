
#include <SDL2/SDL_opengl.h>
#include "firstpersoncamera.h"
#include "framework/utils.h"

FirstPersonCamera::FirstPersonCamera (Display *display)
	: PerspectiveCamera (display),  x (0.0), y (0.0), z (0.0), altitude (0.0), azimuth (0.0)
{
}

FirstPersonCamera::~FirstPersonCamera ()
{
}

void FirstPersonCamera::load ()
{
	this->PerspectiveCamera::load ();
	
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glRotatef (azimuth, 1, 0, 0);
	glRotatef (altitude, 0, -1, 0);
	glTranslatef (-x, -y, -z);
}

