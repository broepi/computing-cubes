
#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>
#include <string>
#include "framework/error.h"
#include "framework/eventmanager.h"

struct Application : EventManager::Handler
{
	Application () throw (Error);
	~Application ();
	void debugmsg (string);
	void run ();
	void on_event (SDL_Event *);
	
	bool verbose;
	bool running;
	double fps_target;
	EventManager *eventmanager;
};

#endif // APPLICATION_H

