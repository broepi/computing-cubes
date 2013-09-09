
#include <cmath>
#include <list>
#include "world/chunkmap.h"
#include "world/chunk.h"
#include "world/voxeltypemap.h"
#include "framework/utils.h"
#include "firstpersoncamera.h"

using namespace std;

ChunkMap::ChunkMap (GLTexture *terrainTex)
	: terrainTex (terrainTex)
{
}

ChunkMap::~ChunkMap ()
{
}

Voxel ChunkMap::getVoxel (Sint32 x, Sint32 y, Sint32 z)
{
	Sint32 chunkX = x >> CHUNKBITS;
	Sint32 chunkY = y >> CHUNKBITS;
	Sint32 chunkZ = z >> CHUNKBITS;
	Uint8 relX = x & CHUNKMASK;
	Uint8 relY = y & CHUNKMASK;
	Uint8 relZ = z & CHUNKMASK;
	map<ChunkId,Chunk*>::iterator chunkIt = chunks.find (chunkVectorToId (chunkX, chunkY, chunkZ));
	if (chunkIt == chunks.end ())
		return VOXAIR;
	else
		return chunkIt->second->getVoxel (relX, relY, relZ);
}

void ChunkMap::hitFirstBlock (FirstPersonCamera *cam, double length, ChunkMap::HitRecord *hitResult)
{
	double sinAlti = sin (degToRad (cam->altitude));
	double cosAlti = cos (degToRad (cam->altitude));
	double sinAzi = sin (degToRad (cam->azimuth));
	double cosAzi = cos (degToRad (cam->azimuth));
	// advancing vector
	double adv [3] = {cosAzi * sinAlti, sinAzi, cosAzi * cosAlti};
	// ratios
	double advyAdvx, advzAdvx, advxAdvy, advzAdvy, advxAdvz, advyAdvz;
	// sample point
	double spt [3] = {cam->x, cam->y, cam->z};
	// hit list
	list<ChunkMap::HitRecord*> hitList;
	// intersection point
	double isec[3];
	
	if (adv[0] != 0.0) {
		advyAdvx = adv[1] / adv[0];
		advzAdvx = adv[2] / adv[0];
	}
	if (adv[1] != 0.0) {
		advxAdvy = adv[0] / adv[1];
		advzAdvy = adv[2] / adv[1];
	}
	if (adv[2] != 0.0) {
		advxAdvz = adv[0] / adv[2];
		advyAdvz = adv[1] / adv[2];
	}
	
	for (double i = 0; i < length; i++) {
	
		Voxel blockBefore = VOXAIR, blockAfter = VOXAIR;
		
		if (adv[0] > 0) {
			// potentially hitting left face
			isec[0] = ceil (spt[0]);
			double dx = isec[0] - spt[0];
			isec[1] = spt[1] + advyAdvx * dx;
			isec[2] = spt[2] + advzAdvx * dx;
			Sint32 voxelCoordY = floor (isec[1]);
			Sint32 voxelCoordZ = floor (isec[2]);
			Voxel blockBefore = getVoxel (isec[0]-1, voxelCoordY, voxelCoordZ);
			Voxel blockAfter = getVoxel (isec[0], voxelCoordY, voxelCoordZ);
			if (blockBefore == VOXAIR && blockAfter != VOXAIR) {
				HitRecord *newHit = new HitRecord (isec[0], isec[1], isec[2],
					isec[0], voxelCoordY, voxelCoordZ, VOXFACELEFT);
				hitList.push_back (newHit);
			}
		}
		else if (adv[0] < 0) {
			// potentially hitting right face
			isec[0] = floor (spt[0]);
			double dx = isec[0] - spt[0];
			isec[1] = spt[1] + advyAdvx * dx;
			isec[2] = spt[2] + advzAdvx * dx;
			Sint32 voxelCoordY = floor (isec[1]);
			Sint32 voxelCoordZ = floor (isec[2]);
			Voxel blockBefore = getVoxel (isec[0], voxelCoordY, voxelCoordZ);
			Voxel blockAfter = getVoxel (isec[0]-1, voxelCoordY, voxelCoordZ);
			if (blockBefore == VOXAIR && blockAfter != VOXAIR) {
				HitRecord *newHit = new HitRecord (isec[0], isec[1], isec[2],
					isec[0]-1, voxelCoordY, voxelCoordZ, VOXFACERIGHT);
				hitList.push_back (newHit);
			}
		}
		
		if (adv[1] > 0) {
			// potentially hitting bottom face
			isec[1] = ceil (spt[1]);
			double dy = isec[1] - spt[1];
			isec[0] = spt[0] + advxAdvy * dy;
			isec[2] = spt[2] + advzAdvy * dy;
			Sint32 voxelCoordX = floor (isec[0]);
			Sint32 voxelCoordZ = floor (isec[2]);
			Voxel blockBefore = getVoxel (voxelCoordX, isec[1]-1, voxelCoordZ);
			Voxel blockAfter = getVoxel (voxelCoordX, isec[1], voxelCoordZ);
			if (blockBefore == VOXAIR && blockAfter != VOXAIR) {
				HitRecord *newHit = new HitRecord (isec[0], isec[1], isec[2],
					voxelCoordX, isec[1], voxelCoordZ, VOXFACEBOTTOM);
				hitList.push_back (newHit);
			}
		}
		else if (adv[1] < 0) {
			// potentially hitting top face
			isec[1] = floor (spt[1]);
			double dy = isec[1] - spt[1];
			isec[0] = spt[0] + advxAdvy * dy;
			isec[2] = spt[2] + advzAdvy * dy;
			Sint32 voxelCoordX = floor (isec[0]);
			Sint32 voxelCoordZ = floor (isec[2]);
			Voxel blockBefore = getVoxel (voxelCoordX, isec[1], voxelCoordZ);
			Voxel blockAfter = getVoxel (voxelCoordX, isec[1]-1, voxelCoordZ);
			if (blockBefore == VOXAIR && blockAfter != VOXAIR) {
				HitRecord *newHit = new HitRecord (isec[0], isec[1], isec[2],
					voxelCoordX, isec[1]-1, voxelCoordZ, VOXFACETOP);
				hitList.push_back (newHit);
			}
		}
		
		if (adv[2] > 0) {
			// potentially hitting front face
			isec[2] = ceil (spt[2]);
			double dz = isec[2] - spt[2];
			isec[0] = spt[0] + advxAdvz * dz;
			isec[1] = spt[1] + advyAdvz * dz;
			Sint32 voxelCoordX = floor (isec[0]);
			Sint32 voxelCoordY = floor (isec[1]);
			Voxel blockBefore = getVoxel (voxelCoordX, voxelCoordY, isec[2]-1);
			Voxel blockAfter = getVoxel (voxelCoordX, voxelCoordY, isec[2]);
			if (blockBefore == VOXAIR && blockAfter != VOXAIR) {
				HitRecord *newHit = new HitRecord (isec[0], isec[1], isec[2],
					voxelCoordX, voxelCoordY, isec[2], VOXFACEFRONT);
				hitList.push_back (newHit);
			}
		}
		else if (adv[2] > 0) {
			// potentially hitting back face
			isec[2] = floor (spt[2]);
			double dz = isec[2] - spt[2];
			isec[0] = spt[0] + advxAdvz * dz;
			isec[1] = spt[1] + advyAdvz * dz;
			Sint32 voxelCoordX = floor (isec[0]);
			Sint32 voxelCoordY = floor (isec[1]);
			Voxel blockBefore = getVoxel (voxelCoordX, voxelCoordY, isec[2]);
			Voxel blockAfter = getVoxel (voxelCoordX, voxelCoordY, isec[2]-1);
			if (blockBefore == VOXAIR && blockAfter != VOXAIR) {
				HitRecord *newHit = new HitRecord (isec[0], isec[1], isec[2],
					voxelCoordX, voxelCoordY, isec[2]-1, VOXFACEBACK);
				hitList.push_back (newHit);
			}
		}
		
		spt[0] += adv[0];
		spt[1] += adv[1];
		spt[2] += adv[2];
	}
	
	double minDistSqu = length * length;
	HitRecord *minHit = 0;
	list<ChunkMap::HitRecord*>::iterator i;
	for (i = hitList.begin(); i != hitList.end(); i ++) {
		HitRecord *hit = *i;
		double distVec [3];
		distVec[0] = hit->isecPoint[0] - cam->x;
		distVec[1] = hit->isecPoint[1] - cam->y;
		distVec[2] = hit->isecPoint[2] - cam->z;
		double distSqu =
			distVec[0] * distVec[0] + distVec[1] * distVec[1] + distVec[2] * distVec[2];
		if (distSqu < minDistSqu) {
			minDistSqu = distSqu;
			minHit = hit;
		}
	}
	
	if (minHit != 0)
		memcpy (hitResult, minHit, sizeof (ChunkMap::HitRecord));
	else
		*hitResult = HitRecord (0,0,0, 0,0,0, VOXFACEUNDEF);
}

void ChunkMap::draw ()
{
	map<ChunkId,Chunk*>::iterator it;
	for (it = chunks.begin (); it != chunks.end (); it ++) {
		Sint32 chunkX = getChunkX (it->first);
		Sint32 chunkY = getChunkY (it->first);
		Sint32 chunkZ = getChunkZ (it->first);
		it->second->draw (chunkX, chunkY, chunkZ, terrainTex);
	}
}


ChunkMap::HitRecord::HitRecord (double isecPointX, double isecPointY, double isecPointZ,
	Sint32 voxelCoordX, Sint32 voxelCoordY, Sint32 voxelCoordZ, Uint8 face)
{
	isecPoint[0] = isecPointX;
	isecPoint[1] = isecPointY;
	isecPoint[2] = isecPointZ;
	voxelCoord[0] = voxelCoordX;
	voxelCoord[1] = voxelCoordY;
	voxelCoord[2] = voxelCoordZ;
	this->face = face;
}


