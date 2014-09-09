#include "MatchTable.h"

 /* At the beginning, just use
  * the GF(4) example, later design a generator*/
int MATCHTABLE[16] = 
{0,1,2,4,8,3,6,12,11,5,10,7,14,15,13,9};
static int LMATCHTABLE =16;
 /* At the beginning, the length is designed
  * as 16 ~ GF(4) */

static int loop = 0;

void convertIWithMatchTable(int* result1, int* result2)
{
	int length = result1[0];
	
	/*convert two arrays according to the MATCHTABLE*/
	int turn = 0;
	for(turn = START_POINT; turn <=length; turn ++)
	{
		result2[turn] = convertI(result1[turn]);
	}
	
}

void convertIIWithMatchTable(int* result1, int* result2)
{
	int length = result2[0];
	
	/*convert two arrays according to the MATCHTABLE*/
	int turn = 0;
	for(turn = START_POINT; turn <=length; turn ++)
	{
		result1[turn] = convertII(result2[turn]);
	}
	
}

int convertI(int number)
{
	for(loop = 0; loop < LMATCHTABLE; loop++)
	{
		if(number == MATCHTABLE[loop]) 
		/* break once the given value equals to the chosen value from table*/
			break;
	}
	/* return the loop value right after the break excutes, otherwise return 16*/
	return loop;
}

int convertII(int number)
{
	return MATCHTABLE[number];
}

int TableLength()
{
	return LMATCHTABLE;
}
