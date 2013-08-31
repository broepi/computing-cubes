
#include <cstring>
#include "voxels/chunkstore.h"
#include "framework/utils.h"

ChunkStore::ChunkStore ()
{
}

ChunkStore::~ChunkStore ()
{
}

Uint32 ChunkStore::chunkid (Uint32 x, Uint32 y, Uint32 z)
{
	return 
		(x & CHUNKIDMASKX) |
		(y & CHUNKIDMASKY) << CHUNKIDBITSX |
		(z & CHUNKIDMASKZ) << CHUNKIDBITSX << CHUNKIDBITSY;
}

