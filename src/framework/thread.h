
#ifndef THREAD_H
#define THREAD_H

#include <string>
#include <SDL2/SDL.h>

using namespace std;

// abstract class
struct Thread
{
	Thread (string name);
	~Thread ();
	void start ();
	virtual void run () = 0;
	
	bool running;
	string name;
	SDL_Thread *thread;
};

#endif // THREAD_H

