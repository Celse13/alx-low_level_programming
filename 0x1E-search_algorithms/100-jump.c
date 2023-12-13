#include "search_algos.h"

/**
 * jump_search - search element jump search algorithm
 * @array: the list of integers
 * @size: the size of an array
 * @value: the target value
 * Return: index of the target or -1 on failure
**/

int jump_search(int *array, size_t size, int value)
{
	size_t high, low, temp;

    high = sqrt(size);
    low = 0;

	if (array == NULL)
		return (-1);

	printf("Value checked array[%lu] = [%d]\n", low, array[low]);
	while (low < size && array[low] < value)
	{
		low = low + high;
		if (low < size && array[low] < value)
			printf("Value checked array[%lu] = [%d]\n", low, array[low]);

	}
	printf("Value found between indexes [%lu] and [%lu]\n", low - high, low);

	for (temp = low - high; temp <= low && temp < size; temp++)
	{
		printf("Value checked array[%lu] = [%d]\n", temp, array[temp]);
		if (value == array[temp])
			return ((int)temp);
	}
	return (-1);
}
