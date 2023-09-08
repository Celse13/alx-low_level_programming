#include "hash_tables.h"
/**
 *  * hash_table_set - adding element and updating if necessary
 *   * @ht: pointing to the first node of a hash table.
 *    * @key: key to be used to find hash.
 *     * @value: value for the key.
 *      *
 *       * Return: 1 if successful or 0 once it fails.
 *        **/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	char *duplicate_key = NULL;
	char *duplicate_value = NULL;
	unsigned long int hash;
	hash_node_t *current;
	hash_node_t *prev;


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

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(duplicate_key);
		free(duplicate_value);
		return (0);
	}

	new_node->key = duplicate_key;
	new_node->value = duplicate_value;
	new_node->next = NULL;

	if (ht->array[hash] == NULL)
	{
		ht->array[hash] = new_node;
	}
	else
	{
		current = ht->array[hash];
		prev = NULL;

		while (current != NULL)
		{
			if (strcmp(current->key, key) == 0)
			{
				free(current->value);
				current->value = duplicate_value;

				free(duplicate_key);
				free(new_node);

				return (1);
			}
			prev = current;
			current = current->next;
		}

		prev->next = new_node;
	}
	return (1);
}
