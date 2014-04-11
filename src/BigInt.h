#ifndef BIGINT_H
#define BIGINT_H

#define CHUNKWIDTH 100

//types
typedef struct BigIntChunk BigIntChunk;
typedef struct BigInt BigInt;

//methods
BigInt * newBigInt(void);
void freeBigInt(BigInt * object);


struct BigIntChunk
{
	
	BigIntChunk *prev;
	BigIntChunk *next;
	int length;
	
	long long value[CHUNKWIDTH];
	
};

struct BigInt
{
	BigIntChunk *first;
	BigIntChunk *last;
	int length; //length in chunks
};


#endif
