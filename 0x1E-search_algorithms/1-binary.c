#include "search_algos.h"

/**
 * binary_search - search element in by binary_search mechanism
 * @array: the list of integers
 * @size: the size of an array
 * @value: the target value
 * Return: index of the target or -1 on failure
**/

int binary_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t mid_value, i;

	if (array == NULL)
		return (-1);

	while (low <= high)
	{
		mid_value = low + (high - low) / 2;

		printf("Searching in array: ");
		for (i = low; i <= high; i++)
		{
			printf("%d", array[i]);
			if (i < high)
				printf(", ");
			else
				printf("\n");
		}

		if (array[mid_value] == value)
			return (mid_value);

		if (array[mid_value] < value)
			low = mid_value + 1;
		else
			high = mid_value - 1;
	}

	return (-1);
}
