
#ifndef display_H
#define display_H

#include <SDL2/SDL.h>
#include "framework/eventmanager.h"

// abstract class
struct Display : EventManager::Handler
{
	Display (int w, int h);
	~Display ();
	virtual void onEvent (SDL_Event *);
	virtual void clear () = 0;
	virtual void present () = 0;
	
	int w, h;
};

#endif // display_H
