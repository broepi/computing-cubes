
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "framework/display.h"

Display::Display (string wndname, int w, int h) throw (Error)
{
	this->w = w;
	this->h = h;
	
	SDL_GL_SetAttribute (SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute (SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute (SDL_GL_BLUE_SIZE, 8);
	
	window = SDL_CreateWindow (wndname.c_str (), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		w, h, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE );
	
	if (window == 0)
		throw Error ( string ("SDL_CreateWindow: ") + string (SDL_GetError ()) );
	
	renderer = SDL_CreateRenderer (window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	if (renderer == 0)
		throw Error ( string ("SDL_CreateRenderer: ") + string (SDL_GetError ()) );
	
	glcontext = SDL_GL_CreateContext (window);
	
	if (glcontext == 0)
		throw Error ( string ("SDL_GL_CreateContext: ") + string (SDL_GetError ()) );
}

Display::~Display ()
{
	SDL_GL_DeleteContext (glcontext);
	SDL_DestroyRenderer (renderer);
	SDL_DestroyWindow (window);
}

void Display::on_event (SDL_Event *event)
{
	if (event->type == SDL_WINDOWEVENT) {
		if (event->window.event == SDL_WINDOWEVENT_RESIZED) {
			w = event->window.data1;
			h = event->window.data2;
		}
	}
}

void Display::clear ()
{
	glClearColor (0, 0.5, 0.5, 1);
	glClear (GL_COLOR_BUFFER_BIT);
}

void Display::present ()
{
	SDL_GL_SwapWindow (window);
}

