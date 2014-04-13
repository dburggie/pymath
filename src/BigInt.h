#ifndef BIGINT_H
#define BIGINT_H

#define CHUNKWIDTH 100

#include <stdio.h>

/* ##### types ##### */

typedef struct BigIntChunk BigIntChunk;
typedef struct BigInt BigInt;



/* ##### methods ##### */

/** Allocates memory for a new big int object
 *  returns new BigInt object initialized to zero.
 */
BigInt * newBigInt(void);
void freeBigInt(BigInt * object);

/** Sets value of a BigInt object to the value in the third argument.
 *  @param self the object the value will be copied into
 *  @param length the length of the value array
 *  @param value a little endian list of int values representing the value
 */
int setValue(BigInt * self, int length, int * value); // value is a little endian list of ints
char * toString(BigInt * self);



/* ##### structures ##### */

struct BigIntChunk
{
	
	BigIntChunk *prev;
	BigIntChunk *next;
	int length;
	
	int value[CHUNKWIDTH];
	
};

struct BigInt
{
	BigIntChunk *first;
	BigIntChunk *last;
	int length; //length in chunks
};


#endif
