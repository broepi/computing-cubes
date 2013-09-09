
#ifndef CHUNKMAP_H
#define CHUNKMAP_H

#include <map>
#include <SDL2/SDL_types.h>
#include "world/defs.h"

using namespace std;

struct Chunk;
struct GLTexture;
struct FirstPersonCamera;

struct ChunkMap
{
	struct HitRecord
	{
		HitRecord (double isecPointX = 0, double isecPointY = 0, double isecPointZ = 0,
			Sint32 voxelCoordX = 0, Sint32 voxelCoordY = 0, Sint32 voxelCoordZ = 0,
			Uint8 face = VOXFACEUNDEF);
		double isecPoint[3];
		Sint32 voxelCoord[3];
		Uint8 face;
	};
	
	ChunkMap (GLTexture *terrainTex);
	~ChunkMap ();
	Voxel getVoxel (Sint32 x, Sint32 y, Sint32 z);
	void hitFirstBlock (FirstPersonCamera *cam, double length, HitRecord *hitResult);
	void draw ();
	
	GLTexture *terrainTex;
	map<ChunkId,Chunk*> chunks;
};

#endif // CHUNKMAP_H

