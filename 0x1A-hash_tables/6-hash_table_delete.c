#include "hash_tables.h"
/**
 *  * hash_table_delete - freeing up the hash table;
 *   * @ht: pointer to the first nod of the hash
 *   **/

void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *hash_table = ht;
	unsigned long int n = 0;
	hash_node_t *current, *tempor_node;

	if (ht == NULL)
		return;

	while (n < hash_table->size)
	{
		if (hash_table->array[n] != NULL)
		{
			current = hash_table->array[n];
			while (current != NULL)
			{
				tempor_node = current->next;
				free(current->key);
				free(current->value);
				free(current);
				current = tempor_node;
			}

		}
		n++;
	}

	free(hash_table->array);
	free(hash_table);
}
