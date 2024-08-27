#include <stdio.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int array[16] = {
		0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 54, 61, 62, 76, 99
	};
	printf("Found at index: %d\n", exponential_search(array, 16, 76));
	return (0);
}
