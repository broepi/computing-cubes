
#include "framework/display.h"

Display::Display (int w, int h)
{
	this->w = w;
	this->h = h;
}

Display::~Display ()
{
}

void Display::onEvent (SDL_Event *event)
{
	if (event->type == SDL_WINDOWEVENT) {
		if (event->window.event == SDL_WINDOWEVENT_RESIZED) {
			w = event->window.data1;
			h = event->window.data2;
		}
	}
}

