
#include "framework/opengl/objects/vbocomposite.h"
#include "framework/utils.h"

VboComposite::VboComposite ()
{
	vertexBufferName = 0;
	texCoordBufferName = 0;
}

VboComposite::~VboComposite ()
{
}

void recreate (void *data, Uint32 vertexCount, GLenum vertexType, GLenum texCoordType)
{
	/*
	if (vertexBufferName)
		glDeleteBuffers (1, &glDeleteBuffers);
	
	vertexBufferName = glGenBuffers (1);
	glBindBuffer (GL_ARRAY_BUFFER, vertexBufferName);
	switch (vertexType) {
	case
		glBufferData (GL_ARRAY_BUFFER, vertexCount * sizeof (GL_SHORT), vertexCount, GL_STATIC_DRAW);
	}

if self.texcoord_vbo is not None:
glDeleteBuffers (1, [self.texcoord_vbo])
self.texcoord_vbo = glGenBuffers (1)

glBindBuffer (GL_ARRAY_BUFFER, self.texcoord_vbo)
ct_texcoords = (ctypes.c_float * len(texcoords))(*texcoords)
glBufferData (GL_ARRAY_BUFFER, len (texcoords)*4, ct_texcoords, GL_STATIC_DRAW)

chunk_cache.triangles += len (vertices) / 3

self.vertex_count = len (vertices)
	*/
}

void draw ()
{
}

