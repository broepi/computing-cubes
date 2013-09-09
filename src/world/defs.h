
#ifndef WORLD_H
#define WORLD_H

/*

	defs.h
	
	World-specific constants, types and functions are defined here.
	
	The faces of a voxel are defined as follows:
	
	y                       y  y                       y  z            +-------> x
	^                       ^  ^                       ^  ^            | 3 - 4
	| 3 - 4           3 - 4 |  | 3 - 4           3 - 4 |  | 3 - 4      | | / |
	| | / |           | / | |  | | / |           | / | |  | | / |      | 1 - 2
	| 1 - 2           1 - 2 |  | 1 - 2           1 - 2 |  | 1 - 2      v
	+-------> x   x <-------+  +-------> z   z <-------+  +-------> x  z
	
	(front side)  (back side)  (right side)  (left side)  (top side)   (bottom side)
	
	first triangle: 1, 2, 4   second triangle: 4, 3, 1

*/

#include <SDL2/SDL_types.h>

#define CHUNKBITS 4  // bits per voxel coordinate in a chunk
#define WORLDBITS 21 // bits per chunk coordinate in a world
#define CHUNKSIZE (1<<CHUNKBITS)
#define WORLDSIZE (1<<WORLDBITS)
#define CHUNKMASK ((1<<CHUNKBITS)-1)
#define WORLDMASK ((1<<WORLDBITS)-1)
#define FULLCHUNKSIZE (CHUNKSIZE*CHUNKSIZE*CHUNKSIZE)

#define TERRAINMAPSIZE 16
#define TERRAINTEXOFFS (1.0 / TERRAINMAPSIZE)

typedef Uint64 ChunkId; // linear adress of a chunk in a world
typedef Uint16 VoxelId; // linear adress of a voxel in a chunk
typedef Uint8 Voxel; // data value of a voxel

enum {
	VOXFACEUNDEF,
	VOXFACEFRONT,
	VOXFACEBACK,
	VOXFACERIGHT,
	VOXFACELEFT,
	VOXFACETOP,
	VOXFACEBOTTOM
};

inline VoxelId voxelVectorToId (Uint8 x, Uint8 y, Uint8 z)
{
	return
		(x & CHUNKMASK) |
		((y & CHUNKMASK) << CHUNKBITS) |
		((z & CHUNKMASK) << CHUNKBITS << CHUNKBITS);
}

inline ChunkId chunkVectorToId (Sint32 x, Sint32 y, Sint32 z)
{
	return
		((ChunkId)(x & WORLDMASK)) |
		((ChunkId)(y & WORLDMASK) << WORLDBITS) |
		((ChunkId)(z & WORLDMASK) << WORLDBITS << WORLDBITS);
}

inline Sint32 getChunkX (ChunkId chunkId)
{
	return (Sint32)((chunkId) & WORLDMASK) << (32-WORLDBITS) >> (32-WORLDBITS);
}

inline Sint32 getChunkY (ChunkId chunkId)
{
	return (Sint32)((chunkId >> WORLDBITS) & WORLDMASK) << (32-WORLDBITS) >> (32-WORLDBITS);
}

inline Sint32 getChunkZ (ChunkId chunkId)
{
	return (Sint32)((chunkId >> WORLDBITS >> WORLDBITS) & WORLDMASK)
		<< (32-WORLDBITS) >> (32-WORLDBITS);
}


#endif // WORLD_H

