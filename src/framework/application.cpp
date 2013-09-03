
#include "framework/application.h"
#include "framework/utils.h"
#include "framework/error.h"
#include "framework/stage.h"

Application::Application ()
{
	running = false;
	fpsTarget = 60.0;
	fpsMeasured = 0.0;
	curStage = &nullStage;
	
	dbgLog << "framework: Application ()\n";
	
	if (SDL_Init (SDL_INIT_VIDEO) != 0)
		throw Error ( string ("SDL_Init: ") + string (SDL_GetError ()) );
	
	performanceFrequency = SDL_GetPerformanceFrequency ();
	
	eventManager = new EventManager ();
	eventManager->addHandler (SDL_QUIT, this);
}

Application::~Application ()
{
	delete eventManager;
}

void Application::run ()
{
	Uint64 lastTick = 0, curTick = 0;
	
	dbgLog << "Application.run\n";
	
	running = true;
	while (running) {
		eventManager->update ();
		curStage->update ();
		curTick = SDL_GetPerformanceCounter ();
		if (curTick-lastTick >= (double)performanceFrequency / fpsTarget) {
			fpsMeasured = (double) performanceFrequency / (curTick-lastTick);
			lastTick = curTick;
			displayClear ();
			curStage->drawScene ();
			displayPresent ();
		}
	}
	
	dbgLog << "Application.run finish\n";
}

void Application::onEvent (SDL_Event *event)
{
	if (event->type == SDL_QUIT) {
		running = false;
	}
}

