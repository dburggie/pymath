#include <stdio.h>
#include "../src/BigInt.h"

int doTest(int test, char * methodName);
int testSetValue(BigInt * obj);
int testAdd(void);

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
	
	err += doTest(testAdd(), "add()");
	
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
	
	else
	{
		printf("%s passed tests\n", methodName);
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
		printf("  setValue(): chunk count mismatch.");
		printf(" Is %i, should be %i\n", obj->length, chunks);
		return 1;
	}
	
	return 0;
	
}

int testAdd(void)
{
	BigInt * bi1 = newBigInt();
	BigInt * bi2 = newBigInt();
	
	int size = 10;
	
	int array1[size];
	int array2[size];
	int i;
	
	for (i = 0; i < size; i++)
	{
		array1[i] = i;
		array2[i] = size - i;
	}
	
	setValue(bi1, size, array1);
	setValue(bi2, size, array2);
	add(bi1, bi2);
	
	i = 0;
	int err = 0;
	int j, chunkcount = 0;
	BigIntChunk * chunk = bi1->first;
	while (chunk)
	{
		printf("testing add operation in chunk %i\n", chunkcount++);
		for (j = 0; j < chunk->length; j++)
		{
			if (chunk->value[j] != size)
			{
				printf("  error at position %i of %i in add():", i, size);
				printf(" value %i should be %i\n", chunk->value[j], size);
				err += 1;
			}
			i++;
		}
		
		chunk = chunk->next;
		
	}
	
	if (err)
	{
		printf("  add() method error count: %i\n", err);
		return 1;
	}
	
	return 0;
}






