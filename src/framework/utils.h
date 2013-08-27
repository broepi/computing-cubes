
#ifndef utils_H
#define utils_H

#include <string>

using namespace std;

void dbglog (string msg);
int power2_expanded (int input);
string itostr (int i);
string dtostr (double i);

extern bool logging_enabled;

#endif

