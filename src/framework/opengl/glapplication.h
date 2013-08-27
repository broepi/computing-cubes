
#ifndef glapplicaton_H
#define glapplicaton_H

#include "framework/application.h"

struct GLDisplay;

struct GLApplication : Application
{
	GLApplication ();
	~GLApplication ();
	void display_clear ();
	void display_present ();
	
	GLDisplay *display;
};

#endif
