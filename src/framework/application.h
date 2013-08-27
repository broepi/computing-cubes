
#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>
#include "framework/eventmanager.h"

// abstract class
struct Application : EventManager::Handler
{
	Application ();
	~Application ();
	void run ();
	void on_event (SDL_Event *);
	virtual void display_clear () = 0;
	virtual void display_present () = 0;
	virtual void draw_scene () = 0;
	
	bool verbose;
	bool running;
	double fps_target;
	EventManager *eventmanager;
};

#endif // APPLICATION_H

