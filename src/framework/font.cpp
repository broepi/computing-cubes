
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
	
	max_height = 0;
	for (char c = '\x20'; c < '\x7f'; ++ c) {
		int i = (int)c-(int)'\x20';
		FT_UInt glyph_index = FT_Get_Char_Index (face, c);
		
		if (FT_Load_Glyph (face, glyph_index, FT_LOAD_DEFAULT))
			throw Error ( string ("FT_Load_Glyph: ") + string ("") );
		
		if (face->glyph->format != FT_GLYPH_FORMAT_BITMAP) {
			if (FT_Render_Glyph (face->glyph, FT_RENDER_MODE_NORMAL))
				throw Error ( string ("FT_Render_Glyph: ") + string ("") );
		}
		
		FT_Bitmap *bmp = &face->glyph->bitmap;

		ascii_bitmaps [i] = new GrayBitmap (bmp->pitch, bmp->width, bmp->rows);
		memcpy (ascii_bitmaps [i]->data, bmp->buffer,
			bmp->pitch * bmp->rows * sizeof (unsigned char));
		
		max_height = max (max_height, bmp->rows);
	}
}

Font::~Font ()
{
	for (char c = '\x20'; c < '\x7f'; ++ c) {
		int i = (int)c-(int)'\x20';
		delete ascii_bitmaps [i];
	}
}

GLTexture *Font::render_text (string text, RGB color)
{
	int text_width = 0;
	
	for (string::iterator i = text.begin();
		i != text.end (); ++i)
	{
		int index = (int)(*i)-(int)'\x20';
		text_width += ascii_bitmaps [index]->width;
	}
	
	int pw = power2_expanded (text_width);
	int ph = power2_expanded (max_height);
	
	unsigned char *pixdata = new unsigned char [pw * ph * 4];
	unsigned int pen = 0;
	for (string::iterator i = text.begin();
		i != text.end (); ++i)
	{
		int index = (int)(*i)-(int)'\x20';
		GrayBitmap *bmp = ascii_bitmaps [index];
		for (int row = 0; row < bmp->rows; row ++) {
			unsigned char *srcptr = bmp->data + row * bmp->pitch;
			unsigned char *destptr = pixdata + (row * pw + pen)*4;
			for (int col = 0; col < bmp->width; col ++) {
				destptr [0] = color.r;
				destptr [1] = color.g;
				destptr [2] = color.b;
				destptr [3] = srcptr [0];
				destptr += 4;
				srcptr ++;
			}
		}
		pen += bmp->width;
	}
	
	GLTexture *gltexture = new GLTexture (pixdata, text_width, max_height);
	
	return gltexture;
}

Font::GrayBitmap::GrayBitmap (int pitch, int width, int rows)
{
	this->pitch = pitch;
	this->width = width;
	this->rows = rows;
	datalen = pitch*rows;
	data = new unsigned char [datalen];
}

Font::GrayBitmap::~GrayBitmap ()
{
	delete data;
}

