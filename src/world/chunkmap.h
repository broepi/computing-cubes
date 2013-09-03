
#ifndef CHUNKMAP_H
#define CHUNKMAP_H

#include <map>
#include "world/world.h"

using namespace std;

struct Chunk;

struct ChunkMap
{
	ChunkMap ();
	~ChunkMap ();
	Voxel getVoxel (Sint32 x, Sint32 y, Sint32 z);
	
	map<ChunkId,Chunk*> chunks;
};

#endif // CHUNKMAP_H

