
#include "framework/eventmanager.h"

EventManager::EventManager ()
{
}

EventManager::~EventManager ()
{
}

void EventManager::add_handler (Uint32 eventid, Handler *handler)
{
	BPList<Handler> *handlerlist = handlermap.get_value (eventid);
	
	if (handlerlist) {
	}
	else {
	}
}
