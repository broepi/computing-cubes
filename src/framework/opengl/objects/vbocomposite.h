
#ifndef VBOCOMPOSITE_H
#define VBOCOMPOSITE_H

#include <SDL2/SDL_opengl.h>

struct VboComposite
{
	VboComposite ();
	~VboComposite ();
	
	GLuint vertexBufferName;
	GLuint texCoordBufferName;
};

#endif // VBOCOMPOSITE_H

