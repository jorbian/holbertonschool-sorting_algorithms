#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

static size_t find_max(int *array, size_t size);
static int *initalize_count(size_t size);

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

	size_t i;

	new_count = malloc(sizeof(int) * size + 1);
	if (!new_count)
		return (NULL);

	for (i = 0; i <= size; i++)
		new_count[i] = 0;

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
 * counting_sort - implementation of counting sort
 * @array: an array of positive integers to be sorted
 * @size: how many such integers there are
*/
void counting_sort(int *array, size_t size)
{
	int *sorted_array;
	size_t l;

	if (!array || (size < 2))
		return;

	sorted_array = perform_sort(array, size);
	if (sorted_array == NULL)
		return;

	for (l = 0; l < size; l++)
		array[l] = sorted_array[l];

	free(sorted_array);
}
