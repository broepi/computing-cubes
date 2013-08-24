
#ifndef display_H
#define display_H

#include <string>
#include <SDL2/SDL.h>
#include "framework/error.h"
#include "framework/eventmanager.h"

using namespace std;

struct Display : EventManager::Handler
{
	Display (string wndname = "SDL Window", int w = 800, int h = 600) throw (Error);
	~Display ();
	void on_event (SDL_Event *);
	void clear ();
	void present ();
	
	int w, h;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_GLContext glcontext;
};

#endif // display_H
