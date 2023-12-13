#include "search_algos.h"

/**
 * recursion - performing advanced binary search recursion
 * @array: the list of integers
 * @start: starting boundary
 * @end: end boundary
 * @value: the target value
 * Return: index of the target or -1 on failure
**/

int recursion(int *array, size_t start, size_t end, int value)
{
	size_t temp;

	if (start > end)
		return (-1);

	printf("Searching in array: %d", array[start]);
	for (temp = start + 1; temp <= end; temp++)
		printf(", %d", array[temp]);
	printf("\n");

	temp = start + (end - start) / 2;

	if ((temp == 0 || array[temp - 1] < value) && array[temp] == value)
		return ((int)temp);

	if (value > array[temp])
		return (recursion(array, temp + 1, end, value));

	return (recursion(array, start, temp, value));
}

/**
 * advanced_binary - search element by advanced_binary
 * @array: the list of integers
 * @size: the size of an array
 * @value: the target value
 * Return: index of the target or -1 on failure
**/
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (recursion(array, 0, size - 1, value));
}
