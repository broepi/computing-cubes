
#ifndef gldisplay_H
#define gldisplay_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "framework/display.h"

using namespace std;

struct GLDisplay : Display
{
	GLDisplay (string wndname = "One of those windows", int w = 800, int h = 600);
	~GLDisplay ();
	void on_event (SDL_Event *);
	void clear ();
	void present ();
	void toggle_screen_drawmode ();
	 
	SDL_Window *window;
	SDL_GLContext glcontext;
};

#endif
