
#ifndef CHUNKSTORE_H
#define CHUNKSTORE_H

#include <map>
#include <SDL2/SDL_types.h>

#define CHUNKIDBITSX 10
#define CHUNKIDBITSY 10
#define CHUNKIDBITSZ 10
#define CHUNKIDMASKX ((2<<CHUNKIDBITSX)-1)
#define CHUNKIDMASKY ((2<<CHUNKIDBITSY)-1)
#define CHUNKIDMASKZ ((2<<CHUNKIDBITSZ)-1)

using namespace std;

struct Chunk;

struct ChunkStore
{
	ChunkStore ();
	~ChunkStore ();
	Uint32 chunkid (Uint32 x, Uint32 y, Uint32 z);
	
	map<Uint32,Chunk*> chunks;
};

#endif // CHUNKSTORE_H

