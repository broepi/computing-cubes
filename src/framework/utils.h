
#ifndef utils_H
#define utils_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

using namespace std;

int power2_expanded (int input);
unsigned int getch_utf8 (unsigned char **strptr);

struct RGB : SDL_Color
{
	RGB (unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);
};

struct Logger
{
	Logger ();
	template <typename T> Logger &operator<< (const T &x);
	
	bool enabled;
};

template <typename T>
Logger &Logger::operator<< (const T &x)
{
	if (enabled)
		cout << x;
	return *this;
}

extern Logger dbglog;

#endif

