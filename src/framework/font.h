
#ifndef font_H
#define font_H

#include <string>
#include <vector>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "framework/utils.h"

using namespace std;

struct GLTexture;
struct GrayBitmap;

struct Font
{
	struct GrayBitmap
	{
		GrayBitmap (int pitch, int width, int rows);
		~GrayBitmap ();
		
		int datalen, pitch, width, rows;
		unsigned char *data;
	};

	Font (string filename, unsigned long size);
	~Font ();
	GLTexture *render_text (string text, RGB color);
	
	FT_Face face;
	GrayBitmap *ascii_bitmaps [128-32];
	int max_height;
};

#endif

