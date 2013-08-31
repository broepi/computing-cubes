
#include <cstring>
#include "voxels/chunk.h"
#include "framework/utils.h"

Chunk::Chunk ()
{
	memset (&blocks, 0, CHUNK_SIZE);
	vertex_vbo = 0;
	texcoord_vbo = 0;
	vertex_count = 0;
}

Chunk::~Chunk ()
{
}

Uint32 Chunk::blockindex (Uint32 x, Uint32 y, Uint32 z)
{
	return 
		(x & BLOCKIDMASKX) |
		(y & BLOCKIDMASKY) << BLOCKIDBITSX |
		(z & BLOCKIDMASKZ) << BLOCKIDBITSX << BLOCKIDBITSY;
	//return x + y * CHUNK_SIZE_X + z * CHUNK_SIZE_X * CHUNK_SIZE_Y;
}

Uint8 Chunk::get (Uint32 x, Uint32 y, Uint32 z)
{
	return blocks [blockindex (x,y,z)];
}

void Chunk::put (Uint32 x, Uint32 y, Uint32 z, Uint8 val)
{
	blocks [blockindex (x,y,z)] = val;
}

