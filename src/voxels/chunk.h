
#ifndef CHUNK_H
#define CHUNK_H

#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_types.h>

#define BLOCKIDBITSX 4
#define BLOCKIDBITSY 4
#define BLOCKIDBITSZ 4
#define BLOCKIDMASKX ((1<<BLOCKIDBITSX)-1)
#define BLOCKIDMASKY ((1<<BLOCKIDBITSY)-1)
#define BLOCKIDMASKZ ((1<<BLOCKIDBITSZ)-1)
#define CHUNKSIZE (1<<BLOCKIDBITSX) * (1<<BLOCKIDBITSY) * (1<<BLOCKIDBITSZ)

#define CHUNK_SIZE_X 16
#define CHUNK_SIZE_Y 16
#define CHUNK_SIZE_Z 16
#define CHUNK_SIZE CHUNK_SIZE_X * CHUNK_SIZE_Y * CHUNK_SIZE_Z

struct Chunk
{
	Chunk ();
	~Chunk ();
	Uint32 blockindex (Uint32 x, Uint32 y, Uint32 z);
	Uint8 get (Uint32 x, Uint32 y, Uint32 z);
	void put (Uint32 x, Uint32 y, Uint32 z, Uint8 val);
	
	Uint8 blocks [CHUNK_SIZE];
	GLuint vertex_vbo;
	GLuint texcoord_vbo;
	Uint32 vertex_count;
};

#endif // CHUNK_H

