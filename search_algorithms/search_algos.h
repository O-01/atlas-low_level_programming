#ifndef _SEARCH_ALGOS_H_
#define _SEARCH_ALGOS_H_

#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define POS(a, l, h, v) \
	(l + (((double)((h) - (l)) / ((a)[(h)] - (a)[(l)])) * ((v) - (a)[(l)])))

int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);

#endif
