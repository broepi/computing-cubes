
#include <iostream>
#include "framework/error.h"
#include "framework/utils.h"
#include "computingcubes.h"

using namespace std;

int main (int argc, char *argv[])
{
	ComputingCubes *app;
	
	dbgLog.enabled = true;
	
	cout << "Computing Cubes" << endl;
	
	try {
		app = new ComputingCubes ();
	}
	catch (Error e) {
		cerr << e.msg << endl;
		return -1;
	}
	app->run ();
	delete app;
	
	return 0;
}
