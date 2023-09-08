#include "hash_tables.h"
/**
 *  * key_index - return the index of a key
 *   * @key: return the value of the provided key
 *    * @size: size of the entire array to be looked up
 *     * Return: the index of the key
 *     **/

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_index = hash_djb2(key) % size;

	return (hash_index);
}
