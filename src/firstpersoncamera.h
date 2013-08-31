
#ifndef FIRSTPERSONCAMERA_H
#define FIRSTPERSONCAMERA_H

#include "framework/opengl/perspectivecamera.h"

struct FirstPersonCamera : PerspectiveCamera
{
	FirstPersonCamera (Display *display);
	~FirstPersonCamera ();
	void load ();
	
	double x, y, z;
	double altitude; // angle of right-turn
	double azimuth; // angle of looking up
};

#endif // FIRSTPERSONCAMERA_H

