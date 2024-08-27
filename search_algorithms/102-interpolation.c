#include "search_algos.h"

/**
 * interpolation_search - searches for value in sorted array of integers using
 *                        interpolation search algorithm
 * @array: pointer to first element of array to search
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located upon success, -1 otherwise
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t lo = 0, hi = size - 1, pos = 0;

	if (!array || !size)
		return (-1);
	for (pos = POS(array, lo, hi, value);
		lo < hi && value >= array[lo] && value <= array[hi];
		pos = POS(array, lo, hi, value))
	{
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return (pos);
		else if (array[pos] < value)
			lo = pos;
		else if (array[pos] > value)
			hi = pos;
	}
	printf("Value checked array[%lu] is out of range\n", pos);
	return (-1);
}
