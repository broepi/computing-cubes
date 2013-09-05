
#include <string.h>
#include "world/voxeltypemap.h"
#include "framework/utils.h"
#include "world/defs.h"

VoxelTypeMap voxelTypeMap;

VoxelTypeMap::VoxelType::VoxelType (Uint32 topFrame, Uint32 bottomFrame, Uint32 sideFrame)
	: topFrame (topFrame), bottomFrame (bottomFrame), sideFrame (sideFrame)
{
	topFrameU = topFrame % TERRAINMAPSIZE / (float) TERRAINMAPSIZE;
	topFrameV = topFrame / TERRAINMAPSIZE / (float) TERRAINMAPSIZE;
	bottomFrameU = bottomFrame % TERRAINMAPSIZE / (float) TERRAINMAPSIZE;
	bottomFrameV = bottomFrame / TERRAINMAPSIZE / (float) TERRAINMAPSIZE;
	sideFrameU = sideFrame % TERRAINMAPSIZE / (float) TERRAINMAPSIZE;
	sideFrameV = sideFrame / TERRAINMAPSIZE / (float) TERRAINMAPSIZE;
	
	GLfloat buf1 [] = {
		topFrameU,                  topFrameV + TERRAINTEXOFFS,
		topFrameU + TERRAINTEXOFFS, topFrameV + TERRAINTEXOFFS,
		topFrameU + TERRAINTEXOFFS, topFrameV,
		topFrameU + TERRAINTEXOFFS, topFrameV,
		topFrameU,                  topFrameV,
		topFrameU,                  topFrameV + TERRAINTEXOFFS
	};
	memcpy (topTexCoords, buf1, sizeof (buf1));
	
	GLfloat buf2 [] = {
		bottomFrameU,                  bottomFrameV + TERRAINTEXOFFS,
		bottomFrameU + TERRAINTEXOFFS, bottomFrameV + TERRAINTEXOFFS,
		bottomFrameU + TERRAINTEXOFFS, bottomFrameV,
		bottomFrameU + TERRAINTEXOFFS, bottomFrameV,
		bottomFrameU,                  bottomFrameV,
		bottomFrameU,                  bottomFrameV + TERRAINTEXOFFS
	};
	memcpy (bottomTexCoords, buf2, sizeof (buf2));
	
	GLfloat buf3 [] = {
		sideFrameU,                  sideFrameV + TERRAINTEXOFFS,
		sideFrameU + TERRAINTEXOFFS, sideFrameV + TERRAINTEXOFFS,
		sideFrameU + TERRAINTEXOFFS, sideFrameV,
		sideFrameU + TERRAINTEXOFFS, sideFrameV,
		sideFrameU,                  sideFrameV,
		sideFrameU,                  sideFrameV + TERRAINTEXOFFS
	};
	memcpy (sideTexCoords, buf3, sizeof (buf3));
}

VoxelTypeMap::VoxelType::~VoxelType ()
{
}

VoxelTypeMap::VoxelTypeMap ()
{
	voxelTypes [VOXGRASS] = new VoxelType (0,1,2);
	voxelTypes [VOXDIRT] = new VoxelType (1,1,1);
	voxelTypes [VOXSTONE] = new VoxelType (3,3,3);
}

VoxelTypeMap::~VoxelTypeMap ()
{
	for (int i=1; i<VOXTYPECOUNT; i++)
		delete voxelTypes [i];
}

