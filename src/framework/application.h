
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
	void onEvent (SDL_Event *);
	virtual void displayClear () = 0;
	virtual void displayPresent () = 0;
	
	bool running;
	double fpsTarget;
	double fpsMeasured;
	Stage *curStage;
	unsigned long performanceFrequency;
	EventManager *eventManager;
};

#endif // APPLICATION_H

