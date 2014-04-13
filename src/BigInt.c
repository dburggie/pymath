#include "BigInt.h"
#include <stdlib.h>

#define ERROR(x) if(x) return 1

/* ##### private method declarations ##### */

static void reset(BigInt * self);
static int append(BigInt * self, BigIntChunk * chunk);
static BigIntChunk * newChunk(void);

static char hex[] = {
		'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
	};




/* ##### public method definitions ##### */

BigInt * newBigInt(void)
{
	
	//allocate memory
	BigInt * object = (BigInt *) malloc(sizeof(BigInt));
	if (object == NULL) { return NULL; }
	
	BigIntChunk * chunk = (BigIntChunk *) malloc(sizeof(BigIntChunk));
	if (chunk == NULL) { free(object); return NULL; }
	
	//initialize data
	object->first = chunk;
	object->last = chunk;
	object->length = 1;
	chunk->prev = NULL;
	chunk->next = NULL;
	chunk->length = 1;
	chunk->value[0] = 0;
	
	return object;
	
}



void freeBigInt(BigInt * object)
{
	//let's avoid freeing a null pointer
	if (object == NULL) return;
	
	//delete all the chunks
	BigIntChunk * chunk = object->first;
	BigIntChunk * next;
	while (chunk != NULL)
	{
		next = chunk->next;
		free(chunk);
		chunk = next;
	}
	
	//free the rest of the object
	free(object);
}



int setValue(BigInt * self, int length, int * value)
{
	
	ERROR(!self || !value);
	
	int numChunks = length / CHUNKWIDTH;
	int tailLength = length % CHUNKWIDTH;
	if (tailLength != 0) numChunks++;
	
	reset(self);
	
	int index = 0, i;
	BigIntChunk * activeChunk;
	
	while (index < length)
	{
		activeChunk = newChunk();
		ERROR(!activeChunk);
		
		for (i = 0; i < CHUNKWIDTH; i++)
		{
			activeChunk->value[i] = value[index];
			activeChunk->length++;
			if (++index >= length) break;
		}
		
		ERROR(append(self, activeChunk));
	}
	
	return 0;
}



char * toString(BigInt * self)
{
	int bytecount = 0;
	BigIntChunk * chunk = self->first;
	while (chunk != NULL)
	{
		bytecount += sizeof(int) * chunk->length;
		chunk = chunk->next;
	}
	
	char * string = malloc( sizeof(char) * (2 * bytecount + 1) );
	string[2* bytecount + 1] = '\0';
	
	int sIndex = 0, cIndex, i;
	chunk = self->first;
	
	while (chunk != NULL)
	{
		for (cIndex = 0; cIndex < chunk->length; cIndex++)
		{
			i = chunk->value[cIndex];
			string[sIndex] = hex[i % 16];
			sIndex++; i = i >> 4;
			string[sIndex] = hex[i % 16];
			sIndex++; i = i >> 4;
			string[sIndex] = hex[i % 16];
			sIndex++; i = i >> 4;
			string[sIndex] = hex[i % 16];
			sIndex++; i = i >> 4;
			string[sIndex] = hex[i % 16];
			sIndex++; i = i >> 4;
			string[sIndex] = hex[i % 16];
			sIndex++; i = i >> 4;
			string[sIndex] = hex[i % 16];
			sIndex++; i = i >> 4;
			string[sIndex] = hex[i % 16];
			sIndex++; i = i >> 4;
		}
		
		chunk = chunk->next;
	}
	
	return string;
}



/* ##### private member definitions ##### */

static void reset(BigInt * self)
{
	BigIntChunk * chunk = self->first;
	BigIntChunk * next;
	
	while (chunk)
	{
		next = chunk->next;
		free(chunk);
		chunk = next;
	}
}


static int append(BigInt * self, BigIntChunk * chunk)
{
	ERROR(!self || !chunk);
	
	self->length++;
	chunk->prev = self->last;
	self->last->next = chunk;
	self->last = chunk;
	
	return 0;
}


static BigIntChunk * newChunk(void)
{
	BigIntChunk * self = (BigIntChunk *)malloc(sizeof(BigIntChunk));
	if (!self)
	{
		printf("malloc fail in private method newChunk in BigInt.c");
		return self;
	}
	
	
	self->prev = NULL;
	self->next = NULL;
	self->length = 1;
	self->value[0] = 0;
	return self;
}
