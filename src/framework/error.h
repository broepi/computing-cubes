
#ifndef ERROR_H
#define ERROR_H

#include <string>

using namespace std;

struct Error
{
	Error (string msg);
	
	string msg;
};

#endif // ERROR_H

