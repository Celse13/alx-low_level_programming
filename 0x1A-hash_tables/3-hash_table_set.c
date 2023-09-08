#include "hash_tables.h"
/**
 *  * hash_table_set - adding element and updating if necessary
 *   * @ht: pointing to the first node of a hash table.
 *    * @key: key to be used to find hash.
 *     * @value: value for the key.
 *      * Return: 1 if successful or 0 once it fails.
 *       **/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	char *duplicate_key = NULL, *duplicate_value = NULL;
	unsigned long int hash, n;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	duplicate_key = strdup(key);
	if (duplicate_key == NULL)
		return (0);

	duplicate_value = strdup(value);
	if (duplicate_value == NULL)
	{
		free(duplicate_key);
		return (0);
	}
	hash = key_index((const unsigned char *)key, ht->size);
	n = hash;
	while (ht->array[n] != NULL)
	{
		if (strcmp(ht->array[n]->key, key) == 0)
		{
			free(ht->array[n]->value);
			ht->array[n]->value = duplicate_value;
			return (1);
		}
		n++;
	}
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	{
		free(duplicate_key);
		free(duplicate_value);
		return (0);
	}
	new_node->key = duplicate_key;
	new_node->value = duplicate_value;
	new_node->next = ht->array[hash];
	ht->array[hash] = new_node;
	return (1);
}
