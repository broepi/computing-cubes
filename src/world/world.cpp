
#include "world/world.h"

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
		(x & WORLDMASK) |
		((y & WORLDMASK) << WORLDBITS) |
		((z & WORLDMASK) << WORLDBITS << WORLDBITS);
}

