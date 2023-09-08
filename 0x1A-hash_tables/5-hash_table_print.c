#include "hash_tables.h"

/**
 *  * hash_table_print - print the elements of a hash table
 *   * @ht: pointer to the first node of hash table
 *   **/
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *current_node;
	unsigned long int i;
	int status;

	if (ht == NULL)
		return;

	printf("{");
	status = 0;
	i = 0;

	while (i < ht->size)
	{
		current_node = ht->array[i];

		while (current_node != NULL)
		{
			if (status)
				printf(", ");

			printf("'%s': '%s'", current_node->key, current_node->value);
			current_node = current_node->next;
			status = 1;
		}

		i++;
	}

	printf("}\n");
}
