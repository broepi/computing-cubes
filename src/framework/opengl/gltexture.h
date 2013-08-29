
#ifndef gltexture_H
#define gltexture_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "framework/opengl/gldrawable.h"

using namespace std;

struct GLDisplay;

struct GLTexture : GLDrawable
{
	GLTexture (string filename, int cols = 1, int rows = 1);
	GLTexture (SDL_Surface *surf, int cols = 1, int rows = 1);
	GLTexture (unsigned char *data, int w, int h, int cols = 1, int rows = 1);
	~GLTexture ();
	void _load_surface (SDL_Surface *surf);
	void draw ();
	void drawx (int x, int y);

	int w, h; // pixel sizes
	int cols, rows; // number of frame cols and rows
	int fw, fh; // pixel sizes of one frame
	int pw, ph; // pysical (power2) pixel sizes
	double u, v;
	GLuint gltexname;
};

#endif

