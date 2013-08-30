
#include "framework/eventmanager.h"

EventManager::EventManager ()
{
}

EventManager::~EventManager ()
{
}

void EventManager::add_handler (Uint32 eventid, Handler *handler)
{
	handlermap[eventid].insert (handler);
}

void EventManager::remove_handler (Uint32 eventid, Handler *handler)
{
	handlermap[eventid].erase (handler);
}

void EventManager::add_universal_handler (Handler *handler)
{
	universalhandlers.insert (handler);
}

void EventManager::remove_universal_handler (Handler *handler)
{
	universalhandlers.erase (handler);
}

void EventManager::update ()
{
	SDL_Event event;

	while (SDL_PollEvent (&event) == 1) {
		for (set<Handler*>::iterator i = handlermap[event.type].begin ();
			i != handlermap[event.type].end (); ++ i )
		{
			(*i)->on_event (&event);
		}
		
		for (set<Handler*>::iterator i = universalhandlers.begin ();
			i != universalhandlers.end (); ++ i )
		{
			(*i)->on_event (&event);
		}
	}
}

