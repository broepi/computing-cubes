
#include <iostream>
#include <sstream>
#include "framework/utils.h"

bool logging_enabled = true;

void dbglog (string msg)
{
	if (logging_enabled)
		cerr << msg << endl;
}

int power2_expanded (int input)
{
    int value = 1;

    while ( value < input ) {
        value <<= 1;
    }
    return value;
}

string itostr (int i)
{
	stringstream ss;
	ss << i;
	return ss.str ();
}

string dtostr (double d)
{
	stringstream ss;
	ss << d;
	return ss.str ();
}
