
#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <map>
#include <set>
#include <SDL2/SDL.h>

using namespace std;

struct EventManager
{
	struct Handler
	{
		virtual void on_event (SDL_Event *event) = 0;
	};
	
	EventManager ();
	~EventManager ();
	void add_handler (Uint32, Handler*);
	void remove_handler (Uint32, Handler*);
	void route_event (SDL_Event*);
	
	map<Uint32,set<Handler*> > handlermap;
};

#endif // EVENTMANAGER

