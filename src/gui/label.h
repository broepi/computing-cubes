
#ifndef LABEL_H
#define LABEL_H

#include <SDL2/SDL_types.h>
#include "framework/utils.h"

struct Label
{
	Label (string text = "", RGB color = RGB (255,255,255));
	~Label ();
	
	string text;
};

#endif // LABEL_H

