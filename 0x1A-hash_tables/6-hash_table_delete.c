#include "hash_tables.h"
/**
 *  * hash_table_delete - freeing up the hash table;
 *   * @ht: pointer to the first nod of the hash
 *   **/

void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *hash_table;
	unsigned long int n;
	hash_node_t *current, *tempor_node;

	hash_table = ht;
	if (ht == NULL)
		return;
	n = o;
	while (n < ht->size)
	{
		if (ht->array[n] != NULL)
		{
			current = ht->array[n];
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
