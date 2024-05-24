#include "hash_tables.h"

/**
 * key_index - finds index of input key
 * @key: key of which we wish to find the index
 * @size: size of the hash table array
 * Return: index of given key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
