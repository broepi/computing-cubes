
#include <cmath>
#include "world/chunkmap.h"
#include "world/chunk.h"
#include "framework/utils.h"

ChunkMap::ChunkMap ()
{
}

ChunkMap::~ChunkMap ()
{
}

Voxel ChunkMap::getVoxel (Sint32 x, Sint32 y, Sint32 z)
{
	Sint32 chunkX = x >> CHUNKBITS;
	Sint32 chunkY = y >> CHUNKBITS;
	Sint32 chunkZ = z >> CHUNKBITS;
	x &= CHUNKBITS;
	y &= CHUNKBITS;
	z &= CHUNKBITS;
	map<ChunkId,Chunk*>::iterator chunkIt = chunks.find (chunkVectorToId (chunkX, chunkY, chunkZ));
	if (chunkIt == chunks.end ())
		return 0;
	else
		return chunkIt->second->getVoxel (x, y, z);
}

