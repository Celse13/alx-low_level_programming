#include "hash_tables.h"
/**
 *  * hash_table_delete - freeing up the hash table;
 *   * @ht: pointer to the first nod of the hash
 *   **/
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *current_node, *temporary_node;
	unsigned int n;

	if (ht == NULL)
		return;

	for (n = 0; n < ht->size; n++)
	{
		current_node = ht->array[n];
		while (current_node)
		{
			temporary_node = current_node;
			free(temporary_node->key);
			free(temporary_node->value);
			free(temporary_node);
			current_node = current_node->next;
		}
	}
	free(ht->array);
	free(ht);
}
