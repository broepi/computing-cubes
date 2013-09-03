
#include "framework/opengl/glapplication.h"
#include "framework/opengl/gldisplay.h"

GLApplication::GLApplication ()
	: Application ()
{
	display = new GLDisplay ();
	eventManager->addHandler (SDL_WINDOWEVENT, display);
}

GLApplication::~GLApplication ()
{
	delete display;
}

void GLApplication::displayClear ()
{
	display->clear ();
}

void GLApplication::displayPresent ()
{
	display->present ();
}

