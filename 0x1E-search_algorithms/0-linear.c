#include "search_algos.h"

/**
 * linear_search - search element in sequential order
 * @array: the list of integers
 * @size: the size of an array
 * @value: the target value
 * Return: index of the target or -1 on failure
**/

int linear_search(int *array, size_t size, int value)
{
	int i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < (int)size; i++)
	{
		printf("Value checked array[%u] = [%d]\n", i, array[i]);
		if (value == array[i])
			return (i);
	}
	return (-1);
}
