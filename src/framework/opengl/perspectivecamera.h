
#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#include "framework/opengl/camera.h"
#include "framework/display.h"

struct PerspectiveCamera : Camera
{
	PerspectiveCamera (Display *display);
	~PerspectiveCamera ();
	void load ();
	
	Display *display;
	double fovy;
	double znear, zfar;
	bool lefthanded;
};

#endif // PERSPECTIVECAMERA_H

