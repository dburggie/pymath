#include <stdio.h>
#include "../src/BigInt.h"

int doTest(int test, char * methodName);
int testSetValue(BigInt * obj);

int main(void)
{
	int err = 0;
	
	BigInt * obj = newBigInt();
	
	if (obj == NULL)
	{
		printf("newBigInt() method failed. No memory allocated.\n");
		return 0;
	}
	
	else
	{
		printf("value of big int: %i\n", obj->first->value[0]);
		printf("big int at addr : %lli\n", (long long) obj);
	}
	
	err += doTest(testSetValue(obj), "setValue()");
	
	freeBigInt(obj);
	
	if (err)
	{
		printf("BigInt module failed %i test", err);
		if (err > 1) printf("s");
		printf(".\n");
	}
	
	return 0;
	
	
}



int doTest(int test, char * methodName)
{
	if (test)
	{
		printf("failure during test of %s\n", methodName);
	}
	
	return test;
}



int testSetValue(BigInt * obj)
{
	//get an array of ints
	int size = 3007, i;
	int array[size];
	for (i = 0; i < size; i++)
	{
		array[i] = size - i;
	}
	
	//perform setValue operation
	if (setValue(obj, size, array)) return 1;
	
	//no error during method call
	int tailLength = size % CHUNKWIDTH;
	int chunks = size / CHUNKWIDTH;
	if (tailLength) chunks++;
	
	if (obj->length != chunks)
	{
		printf("  setValue(): chunk count mismatch.);
		printf(" Is %i, should be %i\n", obj->length, chunks);
	}
	
	
	
}




