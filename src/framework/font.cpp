
#include <cstring>
#include <algorithm>
#include "framework/font.h"
#include "framework/error.h"
#include "framework/utils.h"
#include "framework/opengl/gltexture.h"

FT_Library library;
bool libLoaded = false;

Font::Font (string filename, unsigned long size)
{
	if (!libLoaded) {
		if (FT_Init_FreeType (&library))
			throw Error ( string ("FT_Init_FreeType: ") + string ("") );
		libLoaded = true;
	}

	if (FT_New_Face (library, filename.c_str(), 0, &face))
		throw Error ( string ("FT_New_Face: ") + filename );

	if (FT_Set_Char_Size (face, size*64, size*64, 0, 0))
		throw Error ( string ("FT_Set_Char_Size: ") + string ("") );

	maxBearing = 0;
	int minBearing = 0;
	int minBearingGlyphRows = 0;
	for (unsigned int c = 0x20; c <= 0xff; ++ c) {
		unsigned int i = c - 0x20;
		FT_UInt glyphIndex = FT_Get_Char_Index (face, c);

		if (FT_Load_Glyph (face, glyphIndex, FT_LOAD_DEFAULT))
			throw Error ( string ("FT_Load_Glyph: ") + string ("") );

		if (face->glyph->format != FT_GLYPH_FORMAT_BITMAP) {
			if (FT_Render_Glyph (face->glyph, FT_RENDER_MODE_NORMAL))
				throw Error ( string ("FT_Render_Glyph: ") + string ("") );
		}

		FT_Bitmap *bmp = &face->glyph->bitmap;

		maxBearing = max (maxBearing, face->glyph->bitmap_top);
		if (
			face->glyph->bitmap_top < minBearing ||
			(face->glyph->bitmap_top == minBearing && minBearingGlyphRows < bmp->rows) )
		{
			minBearingGlyphRows = bmp->rows;
			minBearing = face->glyph->bitmap_top;
		}

		asciiBitmaps [i] = new GlyphBmp (
			bmp->pitch,
			bmp->width,
			bmp->rows,
			face->glyph->bitmap_left,
			face->glyph->bitmap_top,
			face->glyph->advance.x / 64);
		memcpy (asciiBitmaps [i]->data, bmp->buffer,
			bmp->pitch * bmp->rows * sizeof (unsigned char));
	}
	maxHeight = minBearingGlyphRows + maxBearing - minBearing;
}

Font::~Font ()
{
	for (unsigned int c = 0x20; c <= 0xff; ++ c) {
		unsigned int i = c - 0x20;
		delete asciiBitmaps [i];
	}
}

Font::GlyphBmp::GlyphBmp (int pitch, int width, int rows, int left, int top, int advance)
	: left(left), top(top), advance(advance)
{
	this->pitch = pitch;
	this->width = width;
	this->rows = rows;
	dataLen = pitch*rows;
	data = new unsigned char [dataLen];
}

Font::GlyphBmp::~GlyphBmp ()
{
	delete data;
}

