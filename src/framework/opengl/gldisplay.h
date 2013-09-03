
#ifndef gldisplay_H
#define gldisplay_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "framework/display.h"

using namespace std;

struct Camera;

struct GLDisplay : Display
{
	GLDisplay (string wndname = "One of those windows", int w = 800, int h = 600);
	~GLDisplay ();
	void onEvent (SDL_Event *);
	void clear ();
	void present ();
	void activateScreenDrawMode ();
	void activateWorldDrawMode (Camera *cam);
	
	SDL_Window *window;
	SDL_GLContext glContext;
};

#endif
