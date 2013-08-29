
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "framework/opengl/gltexture.h"
#include "framework/error.h"
#include "framework/utils.h"

using namespace std;

GLTexture::GLTexture (string filename, int cols, int rows)
	: cols (cols), rows (rows)
{
	gltexname = 0;
	
	SDL_Surface *surf = IMG_Load (filename.c_str ());
	
	if (surf == 0)
		throw Error ( string ("IMG_Load: ") + string (IMG_GetError ()) );
	
	_load_surface (surf);
	
	SDL_FreeSurface (surf);
}

GLTexture::GLTexture (SDL_Surface *surf, int cols, int rows)
	: cols (cols), rows (rows)
{
	_load_surface (surf);
}

GLTexture::GLTexture (unsigned char *data, int w, int h, int cols, int rows)
	: cols (cols), rows (rows)
{
	this->w = w;
	this->h = h;
	pw = power2_expanded (w);
	ph = power2_expanded (h);
	fw = w / cols;
	fh = h / rows;
	u = (double)w/pw;
	v = (double)h/ph;
	
	glGenTextures (1, &gltexname);
	
	if (gltexname == 0)
		throw Error ( string ("glGenTextures: ") + string ("") );
	
	glBindTexture (GL_TEXTURE_2D, gltexname);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, pw, ph, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
}

GLTexture::~GLTexture ()
{
	glDeleteTextures (1, &gltexname);
}

void GLTexture::_load_surface (SDL_Surface *surf)
{
	w = surf->w;
	h = surf->h;
	pw = power2_expanded (w);
	ph = power2_expanded (h);
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

	SDL_SetSurfaceAlphaMod (surf, 0xff);
	SDL_SetSurfaceBlendMode (surf, SDL_BLENDMODE_NONE);
	
	SDL_Rect rect = {0, 0, w, h};
	SDL_BlitSurface (surf, &rect, tmpsurf, &rect);
	
	glGenTextures (1, &gltexname);
	
	if (gltexname == 0)
		throw Error ( string ("glGenTextures: ") + string ("") );
	
	glBindTexture (GL_TEXTURE_2D, gltexname);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, pw, ph, 0, GL_RGBA, GL_UNSIGNED_BYTE,
		tmpsurf->pixels);

	SDL_FreeSurface (tmpsurf);
}

void GLTexture::draw ()
{
	glEnable (GL_TEXTURE_2D);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture (GL_TEXTURE_2D, gltexname);
	glBegin (GL_QUADS);
	glTexCoord2d (0.0, 0.0);
	glVertex3d (0.0, 0.0, 0.0);
	glTexCoord2d (u,   0.0);
	glVertex3d (w, 0.0, 0.0);
	glTexCoord2d (u,   v);
	glVertex3d (w, h, 0.0);
	glTexCoord2d (0.0, v);
	glVertex3d (0.0, h, 0.0);
	glEnd ();
}

void GLTexture::drawx (int x, int y)
{
	glEnable (GL_TEXTURE_2D);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture (GL_TEXTURE_2D, gltexname);
	glBegin (GL_QUADS);
	glTexCoord2d (0.0, 0.0);
	glVertex3d (x, y, 0.0);
	glTexCoord2d (u,   0.0);
	glVertex3d (x+w, y, 0.0);
	glTexCoord2d (u,   v);
	glVertex3d (x+w, y+h, 0.0);
	glTexCoord2d (0.0, v);
	glVertex3d (x, y+h, 0.0);
	glEnd ();
}

