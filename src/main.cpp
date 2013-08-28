
#include <iostream>
#include "computingcubes.h"
#include "framework/error.h"
#include "framework/utils.h"

using namespace std;

int main (int argc, char *argv[])
{
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
