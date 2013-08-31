
#include "framework/thread.h"
#include "framework/utils.h"

int thread_entry (void *ptr)
{
	Thread *threadinst = (Thread*)ptr;
	threadinst->run ();
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
	thread = SDL_CreateThread (thread_entry, name.c_str(), this);
}

