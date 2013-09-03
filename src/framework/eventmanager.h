
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
		virtual void onEvent (SDL_Event *event) = 0;
	};
	
	EventManager ();
	~EventManager ();
	void addHandler (Uint32, Handler*);
	void removeHandler (Uint32, Handler*);
	void addUniversalHandler (Handler*);
	void removeUniversalHandler (Handler*);
	void update ();
	
	map<Uint32,set<Handler*> > handlerMap;
	set<Handler*> universalHandlers;
};

#endif // EVENTMANAGER

