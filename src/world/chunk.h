
#ifndef CHUNK_H
#define CHUNK_H

#include <SDL2/SDL_types.h>
#define GL_GLEXT_PROTOTYPES
#include <SDL2/SDL_opengl.h>
#include "world/defs.h"


struct ChunkMap;
struct GLTexture;

struct Chunk
{
	Chunk ();
	~Chunk ();
	Voxel getVoxel (Uint8 x, Uint8 y, Uint8 z);
	void setVoxel (Uint8 x, Uint8 y, Uint8 z, Voxel val);
	void recreateMesh (Sint32 chunkX, Sint32 chunkY, Sint32 chunkZ, ChunkMap *chunkMap);
	void draw (Sint32 chunkX, Sint32 chunkY, Sint32 chunkZ, GLTexture *terrainTex);
	
	Voxel voxels [FULLCHUNKSIZE];
	bool meshUpToDate;
	GLuint vertexBufferName;
	GLuint texCoordBufferName;
	Uint32 vertexCount;
};

#endif // CHUNK_H

