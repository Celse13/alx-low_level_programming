#include "hash_tables.h"
/**
 *  * hash_table_get - getting a key form the hash table
 *   * @ht: pointer to the first node of the table
 *    * @key: the key to be used while searching in the hash table
 *     * Return: teh value of the key from the hash table
 *     **/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *current;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	if (index >= ht->size)
		return (NULL);

	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);

		current = current->next;
	}

	return (NULL);
}
