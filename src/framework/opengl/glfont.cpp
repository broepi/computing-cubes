
#include "framework/opengl/glfont.h"
#include "framework/opengl/gltexture.h"
#include "framework/utils.h"

GLFont::GLFont (string filename, unsigned long size)
	: Font (filename, size)
{
}

GLTexture *GLFont::render_text (string text, RGB color)
{
	int text_width = 0;
	const char *cstr;
	
	cstr = text.c_str ();
	while (*cstr) {
		unsigned int unicode = getch_utf8 ((unsigned char**)&cstr);
		int index = unicode - '\x20';
		text_width += ascii_bitmaps [index]->advance;
	}
	
	int pw = power2_expanded (text_width);
	int ph = power2_expanded (max_height);
	
	unsigned char *pixdata = new unsigned char [pw * ph * 4];
	memset (pixdata, 0, pw * ph * 4);
	unsigned int pen = 0;
	
	cstr = text.c_str ();
	while (*cstr) {
		unsigned int unicode = getch_utf8 ((unsigned char**)&cstr);
		int index = unicode - '\x20';
		GlyphBmp *bmp = ascii_bitmaps [index];
		int glyph_offsx = bmp->left;
		int glyph_offsy = max_bearing - bmp->top;
		for (int row = 0; row < bmp->rows; row ++) {
			unsigned char *srcptr  = bmp->data + row * bmp->pitch;
			unsigned char *destptr = pixdata + ((row + glyph_offsy) * pw + glyph_offsx + pen)*4;
			for (int col = 0; col < bmp->width; col ++) {
				destptr [0] = color.r;
				destptr [1] = color.g;
				destptr [2] = color.b;
				destptr [3] = srcptr [0];
				destptr += 4;
				srcptr ++;
			}
		}
		pen += bmp->advance;
	}
	
	GLTexture *gltexture = new GLTexture (pixdata, text_width, max_height);
	
	delete pixdata;
	
	return gltexture;
}
