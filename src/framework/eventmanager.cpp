
#include "framework/eventmanager.h"

EventManager::EventManager ()
{
}

EventManager::~EventManager ()
{
}

void EventManager::addHandler (Uint32 eventId, Handler *handler)
{
	handlerMap[eventId].insert (handler);
}

void EventManager::removeHandler (Uint32 eventId, Handler *handler)
{
	handlerMap[eventId].erase (handler);
}

void EventManager::addUniversalHandler (Handler *handler)
{
	universalHandlers.insert (handler);
}

void EventManager::removeUniversalHandler (Handler *handler)
{
	universalHandlers.erase (handler);
}

void EventManager::update ()
{
	SDL_Event event;

	while (SDL_PollEvent (&event) == 1) {
		for (set<Handler*>::iterator i = handlerMap[event.type].begin ();
			i != handlerMap[event.type].end (); ++ i )
		{
			(*i)->onEvent (&event);
		}
		
		for (set<Handler*>::iterator i = universalHandlers.begin ();
			i != universalHandlers.end (); ++ i )
		{
			(*i)->onEvent (&event);
		}
	}
}

