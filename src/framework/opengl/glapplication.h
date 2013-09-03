
#ifndef glapplicaton_H
#define glapplicaton_H

#include "framework/application.h"

struct GLDisplay;

struct GLApplication : Application
{
	GLApplication ();
	~GLApplication ();
	void displayClear ();
	void displayPresent ();
	
	GLDisplay *display;
};

#endif
