
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include "framework/application.h"

using namespace std;

Application::Application () throw (Error)
{
	verbose = true;
	running = false;
	fps_target = 60.0;
	
	debugmsg ("framework: Application ()");
	
	if (SDL_Init (SDL_INIT_VIDEO) != 0)
		throw Error ( string ("SDL_Init: ") + string (SDL_GetError ()) );
	
	eventmanager = new EventManager ();
	eventmanager->add_handler (SDL_QUIT, this);
	display = new Display ();
	eventmanager->add_handler (SDL_WINDOWEVENT, display);
}

Application::~Application ()
{
	delete display;
	delete eventmanager;
}

void Application::debugmsg (string msg)
{
	if (verbose)
		cout << msg << endl;
}

void Application::run ()
{
	Uint32 lasttick = 0, curtick = 0;
	
	debugmsg ("Application.run");
	
	running = true;
	while (running) {
		SDL_Event event;
		while (SDL_PollEvent (&event) == 1) {
			eventmanager->route_event (&event);
		}
		curtick = SDL_GetTicks ();
		if (curtick-lasttick >= 1000.0/fps_target) {
			lasttick = curtick;
			display->clear ();
			display->present ();
		}
	}
	
	debugmsg ("Application.run finish");
}

void Application::on_event (SDL_Event *event)
{
	if (event->type == SDL_QUIT) {
		running = false;
	}
}

