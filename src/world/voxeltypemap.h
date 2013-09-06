
#ifndef VOXELTYPE_H
#define VOXELTYPE_H

#include <SDL2/SDL_types.h>
#include <SDL2/SDL_opengl.h>
#include "world/defs.h"

enum {
	VOXAIR = 0,
	VOXGRASS,
	VOXDIRT,
	VOXSTONE,
	VOXTYPECOUNT
};

struct VoxelTypeMap
{
	struct VoxelType
	{
		VoxelType (Uint32 topFrame, Uint32 bottomFrame, Uint32 sideFrame);
		~VoxelType ();
		
		Uint32 topFrame, bottomFrame, sideFrame;
		GLfloat topFrameU, topFrameV;
		GLfloat bottomFrameU, bottomFrameV;
		GLfloat sideFrameU, sideFrameV;
		GLfloat topTexCoords [12];
		GLfloat bottomTexCoords [12];
		GLfloat sideTexCoords [12];
	};
	
	VoxelTypeMap ();
	~VoxelTypeMap ();
	
	inline VoxelType *get (Uint8 i) {
		return voxelTypes [i];
	}
	
	VoxelType *voxelTypes [VOXTYPECOUNT];
};

extern VoxelTypeMap voxelTypeMap;

#endif // VOXELTYPE_H

