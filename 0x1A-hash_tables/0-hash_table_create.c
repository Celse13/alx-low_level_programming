#include "hash_tables.h"
/**
 *  * hash_table_create - creating a hash table
 *   * @size: size of new hash table
 *    * Return: pointer to the new created hash table
 *    **/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *n_hash_t;
	unsigned int i = 0;

	n_hash_t = malloc(sizeof(hash_table_t));

	if (n_hash_t == NULL)
		return (NULL);
	n_hash_t->size = size;
	n_hash_t->array = malloc(sizeof(hash_node_t **) * size);

	if (n_hash_t->array == NULL)
	{
		free(n_hash_t);
		return (NULL);
	}

	while (i < size)
	{
		n_hash_t->array[i] = NULL;
		i++;
	}

	return (n_hash_t);

}
