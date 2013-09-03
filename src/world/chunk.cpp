
#include "world/chunk.h"
#include "framework/utils.h"

Chunk::Chunk ()
{
	memset (voxels, 0, sizeof (voxels));
	mesh = 0;
	meshUpToDate = false;
}

Chunk::~Chunk ()
{
}

Voxel Chunk::getVoxel (Uint8 x, Uint8 y, Uint8 z)
{
	return voxels [voxelVectorToId (x,y,z)];
}
