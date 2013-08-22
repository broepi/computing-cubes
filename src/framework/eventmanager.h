
#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SDL2/SDL.h>
#include "bputils/bpmap.h"

using namespace std;

struct EventHandler;

struct EventManager
{
	struct Handler
	{
		virtual void on_event (SDL_Event *event) = 0;
	};
	
	EventManager ();
	~EventManager ();
	void add_handler (Uint32, Handler*);
	void route_event (SDL_Event*);
	
	BPMap<Uint32,BPList<Handler>> handlermap;
};

#endif // EVENTMANAGER

