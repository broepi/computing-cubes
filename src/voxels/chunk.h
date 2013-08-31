
#ifndef CHUNK_H
#define CHUNK_H

#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_types.h>

#define CHUNK_SIZE_X 16
#define CHUNK_SIZE_Y 16
#define CHUNK_SIZE_Z 16
#define CHUNK_SIZE CHUNK_SIZE_X * CHUNK_SIZE_Y * CHUNK_SIZE_Z

struct Chunk
{
	Chunk ();
	~Chunk ();
	Uint32 flatindex (Uint32 x, Uint32 y, Uint32 z);
	
	Uint32 blocks [CHUNK_SIZE];
	GLuint vertex_vbo;
	GLuint texcoord_vbo;
	Uint32 vertex_count;
};

#endif // CHUNK_H

