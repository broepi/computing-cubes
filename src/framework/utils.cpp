
#include <sstream>
#include "framework/utils.h"

Logger dbglog;

int power2_expanded (int input)
{
    int value = 1;

    while ( value < input ) {
        value <<= 1;
    }
    return value;
}

unsigned int getch_utf8 (unsigned char **strptr)
{
	unsigned char *codeseq = *strptr;
	if ( (codeseq[0] & 0x80) == 0)
	{
		(*strptr)+=1;
		return codeseq[0] & 0x7f;
	}
	else if ( (codeseq[0] & 0xe0) == 0xc0 && (codeseq[1] & 0xc0) == 0x80)
	{
		(*strptr)+=2;
		return ((codeseq[0] & 0x1f) << 6) | (codeseq[1] & 0x3f);
	}
	else if ( (codeseq[0] & 0xf0) == 0xe0 && (codeseq[1] & 0xc0) == 0x80 &&
		(codeseq[2] & 0xc0) == 0x80)
	{
		(*strptr)+=3;
		return ((codeseq[0] & 0x0f) << 12) | ((codeseq[1] & 0x3f) << 6) | (codeseq[2] & 0x3f);
	}
	else if ( (codeseq[0] & 0xf8) == 0xf0 && (codeseq[1] & 0xc0) == 0x80 &&
		(codeseq[2] & 0xc0) == 0x80 && (codeseq[3] & 0xc0) == 0x80)
	{
		(*strptr)+=4;
		return ((codeseq[0] & 0x0f) << 18) | ((codeseq[1] & 0x3f) << 12) |
			((codeseq[2] & 0x3f) << 6) | (codeseq[3] & 0x3f);
	}
	else
	{
		return 0;
	}
}

RGB::RGB (unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	this->r = r; this->g = g; this->b = b; this->a = a;
}

Logger::Logger ()
{
	enabled = true;
}

