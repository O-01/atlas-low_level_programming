#include "search_algos.h"

static int binary_search(int *array, size_t size, int value, size_t lo);
static void print_array(int *array, size_t size);

/**
 * exponential_search - searches for value in sorted array of integers using
 *                      exponential search algorithm
 * @array: pointer to first element of array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located upon success, otherwise -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t min = 0;

	if (!array || !size)
		return (-1);
	if (value == array[0])
		return (printf("Value checked array[0] = [%d]\n", array[0]), 0);
	for (min = 1; min < size && value > array[min]; min *= 2)
	{
		printf("Value checked array[%lu] = [%d]\n", min, array[min]);
		if (value == array[min] ||
			min * 2 > size - 1 ||
			(value > array[min] && value < array[MIN(min * 2, size - 1)]))
			break;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
		min, MIN(min * 2, size - 1));
	return (binary_search(array, MIN(min * 2, size - 1), value, MIN(min, size)));
}

/**
 * binary_search - search array for value using binary search algorithm
 * @array: pointer to first element of array to search in
 * @size: number of elements in array
 * @value: value to search for
 * @lo: minimum index within array to search for value in
 * Return: index where value is located upon success, otherwise -1
 */
static int binary_search(int *array, size_t size, int value, size_t lo)
{
	size_t left = 0, right = 0, mid = 0;

	if (!array || !size)
		return (-1);
	for (left = lo, right = size, mid = (left + right) / 2;
		left <= right; mid = (left + right) / 2)
	{
		printf("Searching in array: ");
		print_array(&array[left], (right - left + 1));
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
 * @array: pointer to first element of array to print
 * @size: number of elements in array
 */
static void print_array(int *array, size_t size)
{
	size_t i = 0;

	for (i = 0; array && i < size; ++i)
		printf("%s%d", i > 0 ? ", " : "", array[i]);
	putchar('\n');
}
