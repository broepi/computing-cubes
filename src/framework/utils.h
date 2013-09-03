
#ifndef utils_H
#define utils_H

#include <iostream>
#include <list>
#include <string>
#include <SDL2/SDL.h>

using namespace std;

int power2Expanded (int input);
unsigned int getchUtf8 (unsigned char **strptr);
template<typename T> void extendList (list<T> *l, int count, T *values)
{
	while (count--) {
		l->push_back (*values++);
	}
}

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

extern Logger dbgLog;

#endif

