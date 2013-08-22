
#include <iostream>
#include "framework/framework.h"
#include "computingcubes.h"

using namespace std;

int main (int argc, char *argv[])
{
	ComputingCubes *ccapp;
	
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
