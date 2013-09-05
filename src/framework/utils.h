
#ifndef utils_H
#define utils_H

#include <iostream>
#include <list>
#include <string>
#include <SDL2/SDL.h>

#define PI 3.14159265359

using namespace std;

int power2Expanded (int input);
unsigned int getchUtf8 (unsigned char **strptr);
template<typename T> inline void extendListBy (list<T> *l,  T *values, int count)
{
	while (count--) {
		l->push_back (*values++);
	}
}

inline double radToDeg (double r)
{
	return r * 360.0 / (2.0*PI);
}

inline double degToRad (double d)
{
	return d * (2.0*PI) / 360.0;
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

