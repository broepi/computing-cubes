
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

