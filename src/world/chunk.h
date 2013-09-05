
#ifndef CHUNK_H
#define CHUNK_H

#include <SDL2/SDL_types.h>
#include <SDL2/SDL_opengl.h>
#include "world/defs.h"

struct ChunkMap;

struct Chunk
{
	Chunk ();
	~Chunk ();
	Voxel getVoxel (Uint8 x, Uint8 y, Uint8 z);
	void setVoxel (Uint8 x, Uint8 y, Uint8 z, Voxel val);
	void recreateMesh (Sint32 chunkX, Sint32 chunkY, Sint32 chunkZ, ChunkMap *chunkMap);
	void draw ();
	
	Voxel voxels [FULLCHUNKSIZE];
	bool meshUpToDate;
	GLint *vertices;
	GLfloat *texCoords;
	Uint32 vertexCount;
};

#endif // CHUNK_H

