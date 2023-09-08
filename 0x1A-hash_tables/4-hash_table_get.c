#include "hash_tables.h"
/**
 *  * hash_table_get - getting a key form the hash table
 *   * @ht: pointer to the first node of the table
 *    * @key: the key to be used while searching in the hash table
 *     * Return: teh value of the key from the hash table
 *     **/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int hash;
	hash_node_t *current;

	hash = key_index((const unsigned char *)key, ht->size);

	if (!ht->array[hash] || hash > ht->size)
		return (NULL);

	current = ht->array[hash];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->key);

		current = current->next;
	}
	return (NULL);
}
