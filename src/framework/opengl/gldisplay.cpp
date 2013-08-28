
#include "framework/opengl/gldisplay.h"
#include "framework/error.h"
#include "framework/utils.h"

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

void GLDisplay::on_event (SDL_Event *event)
{
	this->Display::on_event (event);
	if (event->type == SDL_WINDOWEVENT) {
		if (event->window.event == SDL_WINDOWEVENT_RESIZED) {
			glViewport (0, 0, w, h);
		}
	}
}

void GLDisplay::clear ()
{
	glClearColor (0, 0.5, 0.5, 1);
	//glClearColor (1, 1, 1, 1);
	glClear (GL_COLOR_BUFFER_BIT);
}

void GLDisplay::present ()
{
	SDL_GL_SwapWindow (window);
}

void GLDisplay::toggle_screen_drawmode ()
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho (0, w, h, 0, -1, 1);

	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();

	glDisable (GL_DEPTH_TEST);
}
