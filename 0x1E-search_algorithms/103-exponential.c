#include "search_algos.h"

/**
 * exponential_search - search element by exponential_search algorithm
 * @array: the list of integers
 * @size: the size of an array
 * @value: the target value
 * Return: index of the target or -1 on failure
**/
int exponential_search(int *array, size_t size, int value)
{
	size_t rate = 1, low_b, upper_b, mid_value, temp;

	if (array == NULL)
		return (-1);

	while (rate < size && value >= array[rate])
	{
		printf("Value checked array[%lu] = [%d]\n", rate, array[rate]);
		rate *= 2;
	}
	low_b = rate / 2;
	upper_b = rate < size ? rate : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", low_b, upper_b);

	while (low_b <= upper_b)
	{
		mid_value = (low_b + upper_b) / 2;
		printf("Searching in array: ");
		for (temp = low_b; temp <= upper_b; temp++)
		{
			printf("%d", array[temp]);
			if (temp < upper_b)
				printf(", ");
		}
		printf("\n");

		if (value == array[mid_value])
			return ((int)mid_value);
		if (array[mid_value] < value)
			low_b = mid_value + 1;
		else
			upper_b = mid_value - 1;
	}
	return (-1);
}
