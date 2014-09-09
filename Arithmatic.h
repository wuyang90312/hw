#include <stdio.h>
#include "MatchTable.h"
#include "GlobalDefine.h"
 
int Addition(int* add1, int* add2, int llength, int result[ARRAY_DIMENSION][llength+START_POINT]);
int Multiplication(int* mult1, int* mult2, int Tlength, int result[ARRAY_DIMENSION][Tlength]);
int measureFrontZeros(int*);
