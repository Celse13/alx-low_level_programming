#include "search_algos.h"

/**
 * interpolation_search -  search element by interpolation_search  algorithm
 * @array: the list of integers
 * @size: the size of an array
 * @value: the target value
 * Return: index of the target or -1 on failure
**/
int interpolation_search(int *array, size_t size, int value)
{
	size_t start = 0, end = size - 1, temp;

	if (array == NULL)
		return (-1);

	while (size)
	{
		temp = start + (((double)(end - start) /
		(array[end] - array[start])) * (value - array[start]));
		printf("Value checked array[%lu] ", temp);
		if (temp >= size)
		{
			printf("is out of range\n");
			break;
		}
		else
			printf("= [%d]\n", array[temp]);

		if (value == array[temp])
			return ((int)temp);
		if (value > array[temp])
			start = temp + 1;
		else
			end = temp - 1;
	}

	return (-1);
}
