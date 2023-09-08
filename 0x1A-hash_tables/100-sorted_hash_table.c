#include "hash_tables.h"
/**
 *  * shash_table_create - create a sorted hash table
 *   * @size: new size of the sorted hash table
 *    * Return: New sorted hash table
 *    **/
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_s_hash_t;
	unsigned long int i;

	new_s_hash_t = malloc(sizeof(shash_table_t));
	if (new_s_hash_t == NULL)
		return (NULL);

	new_s_hash_t->size = size;
	new_s_hash_t->array = malloc(sizeof(shash_node_t *) * size);
	if (new_s_hash_t->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		new_s_hash_t->array[i] = NULL;
	new_s_hash_t->shead = NULL;
	new_s_hash_t->stail = NULL;

	return (new_s_hash_t);
}

/**
 *  * shash_table_set - adding element in the sorted hash table
 *  @ht: pointer to the first node of shash table
 *   * @key: the key to be inserted in the new hash table
 *    * @value: the value that corresponds to the key
 *     * Return: 1 on success of 0 on failure
 *     **/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *create_node, *swap_node;
	unsigned long int hash;
	char *duplicate_value;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	duplicate_value = strdup(value);
	if (duplicate_value == NULL)
		return (0);

	hash = key_index((const unsigned char *)key, ht->size);
	swap_node = ht->shead;
	while (swap_node)
	{
		if (strcmp(swap_node->key, key) == 0)
		{
			free(swap_node->value);
			swap_node->value = duplicate_value;
			return (1);
		}
		swap_node = swap_node->snext;
	}

	create_node = malloc(sizeof(shash_node_t));
	if (create_node == NULL)
	{
		free(duplicate_value);
		return (0);
	}
	create_node->key = strdup(key);
	if (create_node->key == NULL)
	{
		free(duplicate_value);
		free(create_node);
		return (0);
	}
	create_node->value = duplicate_value;
	create_node->next = ht->array[hash];
	ht->array[hash] = create_node;

	if (ht->shead == NULL)
	{
		create_node->sprev = NULL;
		create_node->snext = NULL;
		ht->shead = create_node;
		ht->stail = create_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		create_node->sprev = NULL;
		create_node->snext = ht->shead;
		ht->shead->sprev = create_node;
		ht->shead = create_node;
	}
	else
	{
		swap_node = ht->shead;
		while (swap_node->snext != NULL && strcmp(swap_node->snext->key, key) < 0)
			swap_node = swap_node->snext;
		create_node->sprev = swap_node;
		create_node->snext = swap_node->snext;
		if (swap_node->snext == NULL)
			ht->stail = create_node;
		else
			swap_node->snext->sprev = create_node;
		swap_node->snext = create_node;
	}

	return (1);
}

/**
 * * shash_table_get - getting a key from the shash table
 * * @ht: pointer to the first node of the hash table
 * * @key: the key to be searched
 * * Return: the value of the key
 * **/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *current_node;
	unsigned long int hash;

	if (ht == NULL || key == NULL)
		return (NULL);

	hash = key_index((const unsigned char *)key, ht->size);
	if (hash >= ht->size)
		return (NULL);

	current_node = ht->shead;
	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value);

		current_node = current_node->snext;
	}
	return (NULL);
}

/**
 * * shash_table_print - printing th element of shash table
 * * @ht: pointer to the first node of the hash table
 * **/
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (!ht)
		return;

	current_node = ht->shead;
	printf("{");
	while (current_node != NULL)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->snext;
		if (current_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * * shash_table_print_rev - printing the reverse of hash table
 * * @ht: pointer to the first node of hash table
 * **/
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (ht == NULL)
		return;

	current_node = ht->stail;
	printf("{");
	while (current_node != NULL)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->sprev;
		if (current_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * * shash_table_delete - freeing up the shash table
 * * @ht:pointer to the first node of shash table
 * **/
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *existing_shash_t = ht;
	shash_node_t *current_node, *swap_node;

	if (ht == NULL)
		return;

	current_node = ht->shead;
	while (current_node)
	{
		swap_node = current_node->snext;
		free(current_node->key);
		free(current_node->value);
		free(current_node);
		current_node = swap_node;
	}

	free(existing_shash_t->array);
	free(existing_shash_t);
}
