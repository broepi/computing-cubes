
#include "framework/application.h"
#include "framework/utils.h"
#include "framework/error.h"
#include "framework/stage.h"

Application::Application ()
{
	verbose = true;
	running = false;
	fps_target = 60.0;
	fps_measured = 0.0;
	cur_stage = &null_stage;
	
	dbglog << "framework: Application ()\n";
	
	if (SDL_Init (SDL_INIT_VIDEO) != 0)
		throw Error ( string ("SDL_Init: ") + string (SDL_GetError ()) );
	
	performance_frequency = SDL_GetPerformanceFrequency ();
	
	eventmanager = new EventManager ();
	eventmanager->add_handler (SDL_QUIT, this);
}

Application::~Application ()
{
	delete eventmanager;
}

void Application::run ()
{
	Uint64 lasttick = 0, curtick = 0;
	
	dbglog << "Application.run\n";
	
	running = true;
	while (running) {
		eventmanager->update ();
		cur_stage->update ();
		curtick = SDL_GetPerformanceCounter ();
		if (curtick-lasttick >= (double)performance_frequency / fps_target) {
			fps_measured = (double) performance_frequency / (curtick-lasttick);
			lasttick = curtick;
			display_clear ();
			cur_stage->draw_scene ();
			display_present ();
		}
	}
	
	dbglog << "Application.run finish\n";
}

void Application::on_event (SDL_Event *event)
{
	if (event->type == SDL_QUIT) {
		running = false;
	}
}

