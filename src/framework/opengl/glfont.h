
#ifndef glfont_H
#define glfont_H

#include <string>
#include "framework/font.h"
#include "framework/utils.h"

using namespace std;

struct GLTexture;

struct GLFont : Font
{
	GLFont (string filename, unsigned long size);

	GLTexture *render_text (string text, RGB color);
};

#endif

