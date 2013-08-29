
#ifndef font_H
#define font_H

#include <string>
#include <vector>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "framework/utils.h"

using namespace std;

struct GLTexture;

struct Font
{
	struct GlyphBmp
	{
		GlyphBmp (int pitch, int width, int rows, int left, int top, int advance);
		~GlyphBmp ();
		
		int datalen, pitch, width, rows;
		int left, top; // left and top bearing
		int advance;
		unsigned char *data;
	};

	Font (string filename, unsigned long size);
	~Font ();
	
	FT_Face face;
	GlyphBmp *ascii_bitmaps [128-32];
	int max_height;
	int max_bearing;
};

#endif

