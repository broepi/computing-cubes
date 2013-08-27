
#ifndef gldrawable_H
#define gldrawable_H

struct GLDisplay;

// interface
struct GLDrawable
{
	virtual void draw (GLDisplay *display) = 0;
};

#endif

