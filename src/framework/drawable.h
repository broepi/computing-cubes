
#ifndef drawable_H
#define drawable_H

struct Display;

// interface
struct Drawable
{
	virtual void draw (Display *display) = 0;
};

#endif

