
#include <cmath>
#include "world/chunkmap.h"
#include "world/chunk.h"
#include "world/voxeltypemap.h"
#include "framework/utils.h"

ChunkMap::ChunkMap (GLTexture *terrainTex)
	: terrainTex (terrainTex)
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
	Uint8 relX = x & CHUNKMASK;
	Uint8 relY = y & CHUNKMASK;
	Uint8 relZ = z & CHUNKMASK;
	map<ChunkId,Chunk*>::iterator chunkIt = chunks.find (chunkVectorToId (chunkX, chunkY, chunkZ));
	if (chunkIt == chunks.end ())
		return VOXAIR;
	else
		return chunkIt->second->getVoxel (relX, relY, relZ);
}

void ChunkMap::draw ()
{
	map<ChunkId,Chunk*>::iterator it;
	for (it = chunks.begin (); it != chunks.end (); it ++) {
		Sint32 chunkX = getChunkX (it->first);
		Sint32 chunkY = getChunkY (it->first);
		Sint32 chunkZ = getChunkZ (it->first);
		it->second->draw (chunkX, chunkY, chunkZ, terrainTex);
	}
}

