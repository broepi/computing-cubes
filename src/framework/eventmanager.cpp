
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

void EventManager::route_event (SDL_Event *event)
{
	for (
		set<Handler*>::iterator i = handlermap[event->type].begin ();
		i != handlermap[event->type].end ();
		++ i )
	{
		(*i)->on_event (event);
	}
}
