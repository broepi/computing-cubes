
#include <iostream>
#include "framework/error.h"
#include "framework/utils.h"
#include "computingcubes.h"
#include "voxels/chunk.h"
#include "voxels/chunkstore.h"

using namespace std;

int main (int argc, char *argv[])
{

	Chunk testchunk;
	ChunkStore teststore;
	
	cout << CHUNKSIZE << endl;

	ComputingCubes *ccapp;
	
	dbglog.enabled = true;
	
	cout << "Computing Cubes" << endl;
	
	try {
		ccapp = new ComputingCubes ();
	}
	catch (Error e) {
		cerr << e.msg << endl;
		return -1;
	}
	ccapp->run ();
	delete ccapp;
	
	return 0;
}
