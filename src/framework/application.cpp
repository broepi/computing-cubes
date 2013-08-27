
#include <SDL2/SDL_ttf.h>
#include "framework/application.h"
#include "framework/utils.h"
#include "framework/error.h"

Application::Application ()
{
	verbose = true;
	running = false;
	fps_target = 60.0;
	
	dbglog ("framework: Application ()");
	
	if (SDL_Init (SDL_INIT_VIDEO) != 0)
		throw Error ( string ("SDL_Init: ") + string (SDL_GetError ()) );
	
	if (TTF_Init () != 0)
		throw Error ( string ("TTF_Init: ") + string (TTF_GetError ()) );
	
	eventmanager = new EventManager ();
	eventmanager->add_handler (SDL_QUIT, this);
}

Application::~Application ()
{
	delete eventmanager;
}

void Application::run ()
{
	Uint32 lasttick = 0, curtick = 0;
	
	dbglog ("Application.run");
	
	running = true;
	while (running) {
		SDL_Event event;
		while (SDL_PollEvent (&event) == 1) {
			eventmanager->route_event (&event);
		}
		curtick = SDL_GetTicks ();
		if (curtick-lasttick >= 1000.0/fps_target) {
			lasttick = curtick;
			display_clear ();
			draw_scene ();
			display_present ();
		}
	}
	
	dbglog ("Application.run finish");
}

void Application::on_event (SDL_Event *event)
{
	if (event->type == SDL_QUIT) {
		running = false;
	}
}

