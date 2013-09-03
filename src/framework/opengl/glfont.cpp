
#include "framework/opengl/glfont.h"
#include "framework/opengl/gltexture.h"
#include "framework/utils.h"

GLFont::GLFont (string filename, unsigned long size)
	: Font (filename, size)
{
}

GLTexture *GLFont::renderText (string text, RGB color)
{
	int textWidth = 0;
	const char *cstr;
	
	cstr = text.c_str ();
	while (*cstr) {
		unsigned int unicode = getchUtf8 ((unsigned char**)&cstr);
		int index = unicode - '\x20';
		textWidth += asciiBitmaps [index]->advance;
	}
	
	int pw = power2Expanded (textWidth);
	int ph = power2Expanded (maxHeight);
	
	unsigned char *pixdata = new unsigned char [pw * ph * 4];
	memset (pixdata, 0, pw * ph * 4);
	unsigned int pen = 0;
	
	cstr = text.c_str ();
	while (*cstr) {
		unsigned int unicode = getchUtf8 ((unsigned char**)&cstr);
		int index = unicode - '\x20';
		GlyphBmp *bmp = asciiBitmaps [index];
		int glyphOffsx = bmp->left;
		int glyphOffsy = maxBearing - bmp->top;
		for (int row = 0; row < bmp->rows; row ++) {
			unsigned char *srcptr  = bmp->data + row * bmp->pitch;
			unsigned char *destptr = pixdata + ((row + glyphOffsy) * pw + glyphOffsx + pen)*4;
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
	
	GLTexture *texture = new GLTexture (pixdata, textWidth, maxHeight);
	
	delete pixdata;
	
	return texture;
}
