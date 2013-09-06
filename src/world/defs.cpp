
#include <iostream>
#include "world/defs.h"

using namespace std;

VoxelId voxelVectorToId (Uint8 x, Uint8 y, Uint8 z)
{
	return
		(x & CHUNKMASK) |
		((y & CHUNKMASK) << CHUNKBITS) |
		((z & CHUNKMASK) << CHUNKBITS << CHUNKBITS);
}

ChunkId chunkVectorToId (Sint32 x, Sint32 y, Sint32 z)
{
	return
		((ChunkId)x & WORLDMASK) |
		((ChunkId)(y & WORLDMASK) << WORLDBITS) |
		((ChunkId)(z & WORLDMASK) << WORLDBITS << WORLDBITS);
}

