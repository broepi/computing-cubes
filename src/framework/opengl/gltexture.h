
#ifndef gltexture_H
#define gltexture_H

#include <string>
#include <SDL2/SDL_opengl.h>
#include "framework/opengl/gldrawable.h"

using namespace std;

struct GLDisplay;

struct GLTexture : GLDrawable
{
	GLTexture (string filename, int cols = 1, int rows = 1);
	~GLTexture ();
	void draw (GLDisplay *display);

	int w, h; // pixel sizes
	int cols, rows; // number of frame cols and rows
	int fw, fh; // pixel sizes of one frame
	int pw, ph; // pysical (power2) pixel sizes
	double u, v;
	GLuint gltexname;
};

#endif

