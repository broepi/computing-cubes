
#include "framework/opengl/glapplication.h"
#include "framework/opengl/gldisplay.h"

GLApplication::GLApplication ()
	: Application ()
{
	display = new GLDisplay ();
	eventmanager->add_handler (SDL_WINDOWEVENT, display);
}

GLApplication::~GLApplication ()
{
	delete display;
}

void GLApplication::display_clear ()
{
	display->clear ();
}

void GLApplication::display_present ()
{
	display->present ();
}

