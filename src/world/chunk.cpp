
#include <cstring>
#include "world/chunk.h"
#include "world/chunkmap.h"
#include "world/voxeltypemap.h"
#include "world/defs.h"
#include "framework/utils.h"
#include "framework/opengl/gltexture.h"

Chunk::Chunk ()
{
	memset (voxels, 0, sizeof (voxels));
	meshUpToDate = false;
	vertexBufferName = 0;
	texCoordBufferName = 0;
	vertexCount = 0;
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
	Sint32 offsX = chunkX * CHUNKSIZE;
	Sint32 offsY = chunkY * CHUNKSIZE;
	Sint32 offsZ = chunkZ * CHUNKSIZE;
	GLshort *vertices, *vertexPtr;
	GLfloat *texCoords, *texCoordPtr;

	vertexPtr = vertices =    new GLshort [8*16*16*6*2*3*3];
	texCoordPtr = texCoords = new GLfloat [8*16*16*6*2*3*2];

	vertexCount = 0;

	for (Uint8 z = 0; z < CHUNKSIZE; z ++) {
		for (Uint8 y = 0; y < CHUNKSIZE; y ++) {
			for (Uint8 x = 0; x < CHUNKSIZE; x ++) {
				Voxel voxel = getVoxel (x, y, z);
				if (voxel != VOXAIR) {
					GLshort llf[] = {x,   y,   z};
					GLshort rlf[] = {x+1, y,   z};
					GLshort luf[] = {x,   y+1, z};
					GLshort ruf[] = {x+1, y+1, z};
					GLshort llb[] = {x,   y,   z+1};
					GLshort rlb[] = {x+1, y,   z+1};
					GLshort lub[] = {x,   y+1, z+1};
					GLshort rub[] = {x+1, y+1, z+1};
					// draw front faces
					if ( z == 0
						? (chunkMap->getVoxel (offsX+x,offsY+y,offsZ+z-1) == VOXAIR)
						: (getVoxel (x,y,z-1) == VOXAIR) )
					{
						memcpy (&vertexPtr[0], llf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[3], rlf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[6], ruf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[9], ruf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[12], luf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[15], llf, 3 * sizeof (GLshort));
						memcpy (texCoordPtr, voxelTypeMap.get(voxel)->sideTexCoords,
							12 * sizeof (GLfloat));
						vertexPtr += 6*3;
						texCoordPtr += 12;
						vertexCount += 6;
					}
					// draw back faces
					if ( z == CHUNKSIZE-1
						? (chunkMap->getVoxel (offsX+x,offsY+y,offsZ+z+1) == VOXAIR)
						: (getVoxel (x,y,z+1) == VOXAIR) )
					{
						memcpy (&vertexPtr[0], rlb, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[3], llb, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[6], lub, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[9], lub, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[12], rub, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[15], rlb, 3 * sizeof (GLshort));
						memcpy (texCoordPtr, voxelTypeMap.get(voxel)->sideTexCoords,
							12 * sizeof (GLfloat));
						vertexPtr += 6*3;
						texCoordPtr += 12;
						vertexCount += 6;
					}
					// draw right faces
					if ( x == CHUNKSIZE-1
						? (chunkMap->getVoxel (offsX+x+1,offsY+y,offsZ+z) == VOXAIR)
						: (getVoxel (x+1,y,z) == VOXAIR) )
					{
						memcpy (&vertexPtr[0], rlf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[3], rlb, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[6], rub, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[9], rub, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[12], ruf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[15], rlf, 3 * sizeof (GLshort));
						memcpy (texCoordPtr, voxelTypeMap.get(voxel)->sideTexCoords,
							12 * sizeof (GLfloat));
						vertexPtr += 6*3;
						texCoordPtr += 12;
						vertexCount += 6;
					}
					// draw left faces
					if ( x == 0
						? (chunkMap->getVoxel (offsX+x-1,offsY+y,offsZ+z) == VOXAIR)
						: (getVoxel (x-1,y,z) == VOXAIR) )
					{
						memcpy (&vertexPtr[0], llb, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[3], llf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[6], luf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[9], luf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[12], lub, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[15], llb, 3 * sizeof (GLshort));
						memcpy (texCoordPtr, voxelTypeMap.get(voxel)->sideTexCoords,
							12 * sizeof (GLfloat));
						vertexPtr += 6*3;
						texCoordPtr += 12;
						vertexCount += 6;
					}
					// draw top faces
					if ( y == CHUNKSIZE-1
						? (chunkMap->getVoxel (offsX+x,offsY+y+1,offsZ+z) == VOXAIR)
						: (getVoxel (x,y+1,z) == VOXAIR) )
					{
						memcpy (&vertexPtr[0], luf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[3], ruf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[6], rub, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[9], rub, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[12], lub, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[15], luf, 3 * sizeof (GLshort));
						memcpy (texCoordPtr, voxelTypeMap.get(voxel)->topTexCoords,
							12 * sizeof (GLfloat));
						vertexPtr += 6*3;
						texCoordPtr += 12;
						vertexCount += 6;
					}
					// draw bottom faces
					if ( y == 0
						? (chunkMap->getVoxel (offsX+x,offsY+y-1,offsZ+z) == VOXAIR)
						: (getVoxel (x,y-1,z) == VOXAIR) )
					{
						memcpy (&vertexPtr[0], llb, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[3], rlb, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[6], rlf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[9], rlf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[12], llf, 3 * sizeof (GLshort));
						memcpy (&vertexPtr[15], llb, 3 * sizeof (GLshort));
						memcpy (texCoordPtr, voxelTypeMap.get(voxel)->bottomTexCoords,
							12 * sizeof (GLfloat));
						vertexPtr += 6*3;
						texCoordPtr += 12;
						vertexCount += 6;
					}
				}
			}
		}
	}
	
	if (vertexBufferName) glDeleteBuffers (1, &vertexBufferName);
	glGenBuffers (1, &vertexBufferName);
	glBindBuffer (GL_ARRAY_BUFFER, vertexBufferName);
	glBufferData (GL_ARRAY_BUFFER, vertexCount * 3 * sizeof (GLshort), vertices, GL_STATIC_DRAW);
	delete [] vertices;
	
	if (texCoordBufferName) glDeleteBuffers (1, &texCoordBufferName);
	glGenBuffers (1, &texCoordBufferName);
	glBindBuffer (GL_ARRAY_BUFFER, texCoordBufferName);
	glBufferData (GL_ARRAY_BUFFER, vertexCount * 2 * sizeof (GLfloat), texCoords, GL_STATIC_DRAW);
	delete [] texCoords;
	
	meshUpToDate = true;
}

void Chunk::draw (Sint32 chunkX, Sint32 chunkY, Sint32 chunkZ, GLTexture *terrainTex)
{
	if (vertexBufferName && texCoordBufferName) {

		glMatrixMode (GL_MODELVIEW);
		glPushMatrix ();
		glTranslated (chunkX * CHUNKSIZE, chunkY * CHUNKSIZE, chunkZ * CHUNKSIZE);

		terrainTex->select ();

		glEnable (GL_CULL_FACE);
		glEnable (GL_TEXTURE_2D);
		glColor3f (1.0, 1.0, 1.0);

		glBindBuffer (GL_ARRAY_BUFFER, vertexBufferName);
		glVertexPointer (3, GL_SHORT, 0, 0);
		glBindBuffer (GL_ARRAY_BUFFER, texCoordBufferName);
		glTexCoordPointer (2, GL_FLOAT, 0, 0);
		glEnableClientState (GL_VERTEX_ARRAY);
		glEnableClientState (GL_TEXTURE_COORD_ARRAY);

		glDrawArrays (GL_TRIANGLES, 0, vertexCount);

		glDisableClientState (GL_VERTEX_ARRAY);
		glDisableClientState (GL_TEXTURE_COORD_ARRAY);
		glBindBuffer (GL_ARRAY_BUFFER, 0);

		glPopMatrix ();
	}
}

