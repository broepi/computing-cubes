
#include "framework/thread.h"
#include "framework/utils.h"

int threadEntry (void *ptr)
{
	Thread *threadInst = (Thread*)ptr;
	threadInst->run ();
}

Thread::Thread (string name)
	: name (name)
{
	running = false;
	thread = 0;
}

Thread::~Thread ()
{
}

void Thread::start ()
{
	running = true;
	thread = SDL_CreateThread (threadEntry, name.c_str(), this);
}

