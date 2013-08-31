
#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>
#include "framework/eventmanager.h"

struct Stage;

// abstract class
struct Application : EventManager::Handler
{
	Application ();
	~Application ();
	void run ();
	void on_event (SDL_Event *);
	virtual void display_clear () = 0;
	virtual void display_present () = 0;
	
	bool running;
	double fps_target;
	double fps_measured;
	Stage *cur_stage;
	unsigned long performance_frequency;
	EventManager *eventmanager;
};

#endif // APPLICATION_H

