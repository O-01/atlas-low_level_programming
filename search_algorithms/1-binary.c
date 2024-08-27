#include "search_algos.h"

/**
 * binary_search - search array for value using binary search algorithm
 * @array: object array
 * @size: size of array
 * @value: value to be sought within array
 * Return: index where/if value found, -1 upon value not found or NULL array
 */

int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = 0, mid = 0;

	if (!array || !size)
		return (-1);

	for (left = 0, right = size - 1;
	     left <= right;)
	{
		printf("Searching in array: ");
		print_array(&array[left], (right - left + 1));

		mid = (left + right) / 2;
		if (array[mid] < value)
			left = mid + 1;
		else if (array[mid] > value)
			right = mid - 1;
		else
			return (mid);

	}
	return (-1);
}

/**
 * print_array - prints integer array
 * @array: object array
 * @size: size of array
 */

void print_array(const int *array, size_t size)
{
	size_t i = 0;

	for (i = 0; array && i < size; ++i)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
