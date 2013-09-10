
/*

    Computing Cubes
    Copyright (C) 2013  broepi <broepi@broepi.de>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

/*

	main.cpp
	
	The programs entry point of Computing Cubes. Nothing special here.

*/

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

