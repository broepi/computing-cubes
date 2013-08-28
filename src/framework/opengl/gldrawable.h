
#ifndef gldrawable_H
#define gldrawable_H

struct GLDisplay;

// interface
struct GLDrawable
{
	virtual void draw () = 0;
};

#endif

