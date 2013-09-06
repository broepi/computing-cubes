
#ifndef CHUNKMAP_H
#define CHUNKMAP_H

#include <map>
#include <SDL2/SDL_types.h>
#include "world/defs.h"

using namespace std;

struct Chunk;
struct GLTexture;

struct ChunkMap
{
	ChunkMap (GLTexture *terrainTex);
	~ChunkMap ();
	Voxel getVoxel (Sint32 x, Sint32 y, Sint32 z);
	void draw ();
	
	GLTexture *terrainTex;
	map<ChunkId,Chunk*> chunks;
};

#endif // CHUNKMAP_H

