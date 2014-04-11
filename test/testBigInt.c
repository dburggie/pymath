#include <stdio.h>
#include "../src/BigInt.h"

int main(void)
{
	
	BigInt * obj = newBigInt();
	
	if (obj == NULL)
	{
		printf("newBigInt() method failed. No memory allocated.\n");
		return 0;
	}
	
	else
	{
		printf("value of big int: %lli\n", obj->first->value[0]);
		printf("big int at addr : %lli\n", (long long) obj);
	}
	
	freeBigInt(obj);
	
	return 0;
	
	
}
