 #include "Arithmatic.h"
 
static int turn = 0;

int main()
{
	int array1[ARRAY_DIMENSION][3] = {{2, 2, 14},{2, 2, 12}};
	int array2[ARRAY_DIMENSION][5] = {{4, 5, 8, 7, 13},{4, 9, 4, 11, 14}};

	/********* Define the length of the result ********For Addition*****/
    //int llength = (array1[0][0]>array2[0][0])? array1[0][0]:array2[0][0];
	//int result[ARRAY_DIMENSION][llength+START_POINT];
	//Addition(array1[0], array2[0], llength, result);
	/********* Define the length of the result *************************/
	
	
	/********* Define the length of the result ********For Multiplication*****/
    int Tlength = array1[0][0] + array2[0][0];
	int result[ARRAY_DIMENSION][Tlength];
	Multiplication(array1[1], array2[1], Tlength, result);
	
	printf("The coefficient is %d : %d %d %d %d %d\n", result[0][0], result[0][5], result[0][4], result[0][3], result[0][2], result[0][1]);
	printf("The order is %d : %d %d %d %d %d\n", result[1][0], result[1][5], result[1][4], result[1][3], result[1][2], result[1][1]);
	
	int count = measureFrontZeros(result[0]);
	int resultR[ARRAY_DIMENSION][Tlength-count];
	if(count > 0)
	{	
		removeZeros(result[0], Tlength-count, resultR);
	}
	/********* Define the length of the result *************************/
	
	printf("The coefficient is %d : %d %d %d\n", resultR[0][0], resultR[0][3], resultR[0][2], resultR[0][1]);
	printf("The order is %d : %d %d %d\n", resultR[1][0], resultR[1][3], resultR[1][2], resultR[1][1]);
	
	return SUCCESS;
}
 

int Addition(int* add1, int* add2, int llength, int result[ARRAY_DIMENSION][llength+START_POINT])
{
    /*Compare the length of two components, take the shorter length*/
    int slength = (add1[0]<add2[0])? add1[0]:add2[0];
     
    /*fill the first index with the number order*/
    result[0][0] = llength;
    result[1][0] = llength;
     
    /* perform the addition/subtraction */
    for(turn = 1; turn <=slength; turn++ )
    {
        result[0][turn] = add1[turn] ^ add2[turn];
    }
     
    if( llength > slength )
    {
        int* larray = (add1[0]>add2[0]) ? &add1[0]:&add2[0];
        for(turn; turn <= llength; turn++) /*replace with truncation????*/
        {
            result[0][turn] = larray[turn];
        }
    }
    
    /*convert the number form to exponential form*/
    convertIWithMatchTable(result[0], result[1]);
    return SUCCESS;
}


int Multiplication(int* mult1, int* mult2, int Tlength, int result[ARRAY_DIMENSION][Tlength])
{
	int length = mult1[0];
	int iteration = mult2[0];
	/*create a 1-d arrays both of which have the same length as mult1's order*/
	int buff, round;
	int prep[length];
	
	/*fill the first index with the number order*/
    result[0][0] = Tlength-START_POINT;
    result[1][0] = Tlength-START_POINT;
    
    for(turn = 0; turn < length; turn++) /*clean up the prep array at first*/
	{
		prep[turn] = 0;
	}
	
	for(turn = 0; turn < iteration; turn++)
	{
		/*use the current digit of mult2 to multiply mult1*/
		for(round = 0; round < length; round ++)
		{
			//prep2[round] = prep1[round];
			/*first get the exponent, then convert it to coefficient*/
			buff = convertII((mult1[round+START_POINT]+mult2[turn+START_POINT])%TableLength());
			
			/*Use prep as a storage to run the addition*/
			if(round == length - START_POINT)
			{
				prep[round] = buff;
				printf("1.  %d - %d ", prep[round], buff);
			}
			else
			{ 
				prep[round] = buff^prep[round+START_POINT];
				printf("2.  %d - %d    %d", prep[round], buff, prep[round+START_POINT]);
			}
		}
		
		result[0][turn+START_POINT] = prep[ZERO];
		printf("\n this term the item is %d \n", result[0][turn+START_POINT]);
	
	}
	
	/* Cascading the preceedingly left indices */
	for(round = 1; round < length; round ++)
	{
		result[0][turn+round] = prep[round];
	}
	
	/*convert the number form to exponential form*/
    convertIWithMatchTable(result[0], result[1]);
	
	return SUCCESS;  
}

int measureFrontZeros(int* number)
{
	int count = 0;
	for(turn = number[0]; number>0; number--)
	{
		if(number[turn] == 0)
			count ++;
		else
			break;
	}
	
	return count;
}

int removeZeros(int* input, int digit, int result[ARRAY_DIMENSION][digit])
{
	/*fill the first index with the number order*/
    result[0][0] = digit-START_POINT;
    result[1][0] = digit-START_POINT;
    
    for(turn = START_POINT; turn < digit; turn ++)
    {
		result[0][turn] = input[turn];
	}
	
	/*convert the number form to exponential form*/
    convertIWithMatchTable(result[0], result[1]);
    
    return SUCCESS;
}
