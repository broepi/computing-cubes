
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

RGB::RGB (unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	this->r = r; this->g = g; this->b = b; this->a = a;
}

Logger::Logger ()
{
	enabled = true;
}
