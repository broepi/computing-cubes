
#ifndef WORLD_H
#define WORLD_H

/*

	world.h
	
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

VoxelId voxelVectorToId (Uint8 x, Uint8 y, Uint8 z);
ChunkId chunkVectorToId (Sint32 x, Sint32 y, Sint32 z);

#endif // WORLD_H

