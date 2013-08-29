
#include <cstring>
#include <algorithm>
#include "framework/font.h"
#include "framework/error.h"
#include "framework/utils.h"
#include "framework/opengl/gltexture.h"

FT_Library library;
bool lib_loaded = false;

Font::Font (string filename, unsigned long size)
{
	if (!lib_loaded) {
		if (FT_Init_FreeType (&library))
			throw Error ( string ("FT_Init_FreeType: ") + string ("") );
		lib_loaded = true;
	}
	
	if (FT_New_Face (library, filename.c_str(), 0, &face))
		throw Error ( string ("FT_New_Face: ") + string ("") );
	
	if (FT_Set_Char_Size (face, size*64, size*64, 0, 0))
		throw Error ( string ("FT_Set_Char_Size: ") + string ("") );
	
	max_bearing = 0;
	int min_bearing = 0;
	int min_bearing_glyph_rows = 0;
	for (unsigned int c = 0x20; c <= 0xff; ++ c) {
		unsigned int i = c - 0x20;
		FT_UInt glyph_index = FT_Get_Char_Index (face, c);
		
		if (FT_Load_Glyph (face, glyph_index, FT_LOAD_DEFAULT))
			throw Error ( string ("FT_Load_Glyph: ") + string ("") );
		
		if (face->glyph->format != FT_GLYPH_FORMAT_BITMAP) {
			if (FT_Render_Glyph (face->glyph, FT_RENDER_MODE_NORMAL))
				throw Error ( string ("FT_Render_Glyph: ") + string ("") );
		}
		
		FT_Bitmap *bmp = &face->glyph->bitmap;
		
		max_bearing = max (max_bearing, face->glyph->bitmap_top);
		if (
			face->glyph->bitmap_top < min_bearing ||
			(face->glyph->bitmap_top == min_bearing && min_bearing_glyph_rows < bmp->rows) )
		{
			min_bearing_glyph_rows = bmp->rows;
			min_bearing = face->glyph->bitmap_top;
		}

		ascii_bitmaps [i] = new GlyphBmp (
			bmp->pitch,
			bmp->width,
			bmp->rows,
			face->glyph->bitmap_left,
			face->glyph->bitmap_top,
			face->glyph->advance.x / 64);
		memcpy (ascii_bitmaps [i]->data, bmp->buffer,
			bmp->pitch * bmp->rows * sizeof (unsigned char));
	}
	max_height = min_bearing_glyph_rows + max_bearing - min_bearing;
}

Font::~Font ()
{
	for (unsigned int c = 0x20; c <= 0xff; ++ c) {
		unsigned int i = c - 0x20;
		delete ascii_bitmaps [i];
	}
}

Font::GlyphBmp::GlyphBmp (int pitch, int width, int rows, int left, int top, int advance)
	: left(left), top(top), advance(advance)
{
	this->pitch = pitch;
	this->width = width;
	this->rows = rows;
	datalen = pitch*rows;
	data = new unsigned char [datalen];
}

Font::GlyphBmp::~GlyphBmp ()
{
	delete data;
}

