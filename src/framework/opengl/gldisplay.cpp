
#include "framework/opengl/gldisplay.h"
#include "framework/error.h"

GLDisplay::GLDisplay (string wndname, int w, int h)
	: Display (w, h)
{
	SDL_GL_SetAttribute (SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute (SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute (SDL_GL_BLUE_SIZE, 8);
	
	window = SDL_CreateWindow (wndname.c_str (), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		w, h, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE );
	
	if (window == 0)
		throw Error ( string ("SDL_CreateWindow: ") + string (SDL_GetError ()) );
	
	glcontext = SDL_GL_CreateContext (window);
	
	if (glcontext == 0)
		throw Error ( string ("SDL_GL_CreateContext: ") + string (SDL_GetError ()) );
}

GLDisplay::~GLDisplay ()
{
	SDL_GL_DeleteContext (glcontext);
	SDL_DestroyWindow (window);
	this->Display::~Display ();
}

void GLDisplay::clear ()
{
	glClearColor (0, 0.5, 0.5, 1);
	glClear (GL_COLOR_BUFFER_BIT);
}

void GLDisplay::present ()
{
	SDL_GL_SwapWindow (window);
}

