
#include "world/chunk.h"
#include "world/chunkmap.h"
#include "world/voxeltypemap.h"
#include "framework/utils.h"

Chunk::Chunk ()
{
	memset (voxels, 0, sizeof (voxels));
	vertices = 0;
	texCoords = 0;
	vertexCount = 0;
	meshUpToDate = false;
}

Chunk::~Chunk ()
{
}

Voxel Chunk::getVoxel (Uint8 x, Uint8 y, Uint8 z)
{
	return voxels [voxelVectorToId (x,y,z)];
}

void Chunk::setVoxel (Uint8 x, Uint8 y, Uint8 z, Voxel val)
{
	meshUpToDate = false;
	voxels [voxelVectorToId (x,y,z)] = val;
}

void Chunk::recreateMesh (Sint32 chunkX, Sint32 chunkY, Sint32 chunkZ, ChunkMap *chunkMap)
{
	list<GLint> vertexList;
	list<GLfloat> texCoordList;
	bool visible;
	Sint32 offsX = chunkX * CHUNKSIZE;
	Sint32 offsY = chunkY * CHUNKSIZE;
	Sint32 offsZ = chunkZ * CHUNKSIZE;
	
	for (Uint8 z = 0; z < CHUNKSIZE; z ++) {
		for (Uint8 y = 0; y < CHUNKSIZE; y ++) {
			for (Uint8 x = 0; x < CHUNKSIZE; x ++) {
				Voxel voxel = getVoxel (x, y, z);
				if (voxel != VOXAIR) {
					GLint llf[] = {offsX+x, offsY+y, offsZ+z};
					GLint rlf[] = {offsX+x+1, offsY+y, offsZ+z};
					GLint luf[] = {offsX+x, offsY+y+1, offsZ+z};
					GLint ruf[] = {offsX+x+1, offsY+y+1, offsZ+z};
					GLint llb[] = {offsX+x, offsY+y, offsZ+z+1};
					GLint rlb[] = {offsX+x+1, offsY+y, offsZ+z+1};
					GLint lub[] = {offsX+x, offsY+y+1, offsZ+z+1};
					GLint rub[] = {offsX+x+1, offsY+y+1, offsZ+z+1};
					// draw bottoms
					if ( y == 0
						? (chunkMap->getVoxel (offsX+x,offsY+y-1,offsZ+z) == 0)
						: (getVoxel (x,y-1,z) == 0) )
					{
						extendListBy (&vertexList, llf, 3);
						extendListBy (&vertexList, llb, 3);
						extendListBy (&vertexList, rlf, 3);
						extendListBy (&vertexList, llb, 3);
						extendListBy (&vertexList, rlb, 3);
						extendListBy (&vertexList, rlf, 3);
						extendListBy (&texCoordList, voxelTypeMap.get(voxel)->bottomTexCoords, 12);
					}
				}
			}
		}
	}
	
	vertexCount = vertexList.size ();
	
	if (vertices) delete vertices;
	vertices = new GLint [vertexCount*3];
	copy (vertexList.begin (), vertexList.end (), vertices);
	
	if (texCoords) delete texCoords;
	texCoords = new GLfloat [vertexCount*2];
	copy (texCoordList.begin (), texCoordList.end (), texCoords);
	
	meshUpToDate = true;
}

void Chunk::draw ()
{
	glDisable (GL_TEXTURE_2D);
	glEnable (GL_CULL_FACE);
	glBegin (GL_TRIANGLES);
	glColor3f (0.0, 0.5, 0.0);
	for (int i=0; i<vertexCount; i++) {
		glVertex3i (vertices [i*3], vertices [i*3 + 1], vertices [i*3 + 2]);
	}
	glEnd ();
}

