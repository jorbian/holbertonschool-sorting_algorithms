#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

/**
 * find_max - find the largest value in an array of integers
 * @array: an array of positive integers to be sorted
 * @size: how many such integers there are
 *
 * Return: whatever the largest value was
*/
static size_t find_max(int *array, size_t size)
{
	size_t i;
	size_t max = array[0];

	for (i = 1; i < size; i++)
	{
		if ((size_t)array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * initalize_count - creates the count array and populates it with 0s
 * @size: range of the count
 *
 * Return: a pointer to the newly created rray
*/
static int *initalize_count(size_t size)
{
	int *new_count;

	new_count = malloc((size) * sizeof(int));
	if (new_count == NULL)
		return (NULL);

	memset(new_count, 0, size * sizeof(int));

	return (new_count);
}

/**
 * perform_sort - determines what sorted array will look like
 * @array: an array of positive integers to be sorted
 * @size: how many such integers there are
 *
 * Return: pointer new array to change old one to
*/
static int *perform_sort(int *array, size_t size)
{
	int *count, *result, num;
	size_t max_val, i, j, k;

	max_val = find_max(array, size);

	count = initalize_count(max_val);
	if (count == NULL)
		return (NULL);

	result = malloc(sizeof(int) * size);

	if (result != NULL)
	{
		for (i = 0; i < size; i++)
		{
			num = array[i];
			count[num] += 1;
		}
		for (j = 1; j <= max_val; j++)
			count[j] += count[j - 1];

		print_array(count, max_val + 1);

		for (k = 0; k < size; k++)
		{
			result[count[array[k]] - 1] = array[k];
			count[array[k]]--;
		}
	}
	free(count);

	return (result);
}

/**
 * copy_result - copy the results of the sort into original array
 * @original: pointer to the original array
 * @sorted: pointer to the sorted version
 * @size: how big they are
*/
static void copy_result(int *original, int *sorted, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		original[i] = sorted[i];

	free(sorted);
}

/**
 * counting_sort - implementation of counting sort
 * @array: an array of positive integers to be sorted
 * @size: how many such integers there are
*/
void counting_sort(int *array, size_t size)
{
	int *sorted_array;

	if (!array || (size < 2))
		return;

	sorted_array = perform_sort(array, size);
	if (sorted_array == NULL)
		return;

	copy_result(array, sorted_array, size);
}
