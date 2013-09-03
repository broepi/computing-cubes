
#ifndef CHUNK_H
#define CHUNK_H

#include "world/world.h"

struct VboComposite;

struct Chunk
{
	Chunk ();
	~Chunk ();
	Voxel getVoxel (Uint8 x, Uint8 y, Uint8 z);
	void recreateMesh (ChunkMap);
	
	Voxel voxels [CHUNKSIZE];
	VboComposite *mesh;
	bool meshUpToDate;
};

#endif // CHUNK_H

