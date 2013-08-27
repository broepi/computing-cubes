
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "framework/opengl/gltexture.h"
#include "framework/error.h"
#include "framework/utils.h"

using namespace std;

GLTexture::GLTexture (string filename, int cols, int rows)
{
	gltexname = 0;
	
	SDL_Surface *surf = IMG_Load (filename.c_str ());
	
	if (surf == 0)
		throw Error ( string ("IMG_Load: ") + string (IMG_GetError ()) );
	
	w = surf->w;
	h = surf->h;
	pw = power2_expanded (w);
	ph = power2_expanded (h);
	this->cols = cols;
	this->rows = rows;
	fw = w / cols;
	fh = h / rows;
	u = (double)w/pw;
	v = (double)h/ph;
	
	SDL_Surface *tmpsurf = SDL_CreateRGBSurface (0, pw, ph, 32,
#if SDL_BYTEORDER == SDL_LIL_ENDIAN
		0x000000FF,
		0x0000FF00,
		0x00FF0000,
		0xFF000000
#else
		0xFF000000,
		0x00FF0000,
		0x0000FF00,
		0x000000FF
#endif
		);
	
	if (tmpsurf == 0)
		throw Error ( string ("SDL_CreateRGBSurface: ") + string (SDL_GetError ()) );

	SDL_SetSurfaceAlphaMod (tmpsurf, 0xff);
	SDL_SetSurfaceBlendMode (tmpsurf, SDL_BLENDMODE_NONE);
	
	SDL_Rect rect = {0, 0, w, h};
	SDL_BlitSurface (surf, &rect, tmpsurf, &rect);
	
	glGenTextures (1, &gltexname);
	
	dbglog (itostr(gltexname));
	cout << w << " " << h << " " << pw << " " << ph << endl;
	cout << u << " " << v << endl;
	
	if (gltexname == 0)
		throw Error ( string ("glGenTextures: ") + string ("") );
	
	glBindTexture (GL_TEXTURE_2D, gltexname);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, pw, ph, 0, GL_RGBA, GL_UNSIGNED_BYTE,
		tmpsurf->pixels);

	SDL_FreeSurface (tmpsurf);
	SDL_FreeSurface (surf);
}

GLTexture::~GLTexture ()
{
}

void GLTexture::draw (GLDisplay *display)
{
	glEnable (GL_TEXTURE_2D);
	glBindTexture (GL_TEXTURE_2D, gltexname);
	glBegin (GL_QUADS);
	glTexCoord2d (0.0, 0.0);
	glVertex3d (0.0, 0.0, 0.0);
	glTexCoord2d (u,   0.0);
	glVertex3d (1.0, 0.0, 0.0);
	glTexCoord2d (u,   v);
	glVertex3d (1.0, 1.0, 0.0);
	glTexCoord2d (0.0, v);
	glVertex3d (0.0, 1.0, 0.0);
	glEnd ();
}

