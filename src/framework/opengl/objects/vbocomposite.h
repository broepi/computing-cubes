
#ifndef VBOCOMPOSITE_H
#define VBOCOMPOSITE_H

#include <SDL2/SDL_types.h>
#include <SDL2/SDL_opengl.h>

struct VboComposite
{
	VboComposite ();
	~VboComposite ();
	void recreate (void *data, Uint32 vertexCount, GLenum vertexType, GLenum texCoordType);
	void draw ();
	
	GLuint vertexBufferName;
	GLuint texCoordBufferName;
};

#endif // VBOCOMPOSITE_H

