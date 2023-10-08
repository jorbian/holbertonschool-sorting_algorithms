#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

/**
 * shell_sort - implementation of shell sort algorithm
 * @array: an array of positive integers to be sorted
 * @size: how many such integers there are
*/
void shell_sort(int *array, size_t size)
{
	int i, j;
	int n = size, gap = 1, temp = 0;

	while (gap < n / 3)
		gap = 3 * gap + 1;

	while (gap > 0)
	{
		for (i = gap; i < n; i += 1)
		{
			temp = array[i];
			j = i;
			while (j >= gap && (array[j - gap] > temp))
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = temp;
		}
		gap = gap / 3;
		print_array(array, size);
	}
}
