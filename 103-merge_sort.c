#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

#define LEFT_SIZE(s) (s / 2)
#define RIGHT_SIZE(s) (s - (s / 2))

/**
 * place_element - moves an element into place
 * @original: original array we're sorting
 * @slice: the slice we're working from
 * @i: pointer to target index on original
 * @s: pointer to the index of element we're moving over
*/
static void place_element(int *original, int *slice, size_t *i, size_t *s)
{
	original[(*i)] = slice[(*s)];
	(*i)++;
	(*s)++;
}

/**
 * merge_arrays - sorts and merges arrays created from merge_sort
 * @left: the left array to be sorted
 * @right: the right array to be sorted
 * @original: the array before being split to left and right
 * @size: size of the original array
*/
static void merge_arrays(int *left, int *right, int *original, size_t size)
{
	size_t i = 0, l = 0, r = 0;

	while (l < LEFT_SIZE(size) && r < RIGHT_SIZE(size))
	{
		if (left[l] < right[r])
			place_element(original, left, &i, &l);
		else
			place_element(original, right, &i, &r);
	}

	while (l < LEFT_SIZE(size))
		place_element(original, left, &i, &l);

	while (r < RIGHT_SIZE(size))
		place_element(original, right, &i, &r);

	printf("Merging...\n[left]: ");
	print_array(left, LEFT_SIZE(size));
	printf("[right]: ");
	print_array(right, RIGHT_SIZE(size));
	printf("[Done]: ");
	print_array(original, size);

	free(right);
	free(left);
}

/**
 * allocate_slice - allocates memory for an array of ints
 * @size: size of the array to allocate
 *
 * Return: pointer to the allocated memory
*/
static int *allocate_slice(size_t size)
{
	int *array;

	array = malloc(sizeof(int) * (int)size);
	if (array == NULL)
		return (NULL);

	return (array);
}

/**
 * slice_array - calculates how big the slices needs to be and allocates them
 * @array: the array being sorted
 * @left: the left slice of array
 * @right: the right slice of array
 * @total_size: size of the original array
 *
*/
static void slice_array(int *array, int *left, int *right, size_t total_size)
{
	size_t i, j = 0;

	for (i = 0; i < total_size; i++)
	{
		if (i < LEFT_SIZE(total_size))
			left[i] = array[i];
		else
		{
			right[j] = array[i];
			j++;
		}
	}
}

/**
 * merge_sort - recursively splices an array into smaller arrays for sorting
 * @array: an array of positive integers to be sorted
 * @size: how many such integers there are
*/
void merge_sort(int *array, size_t size)
{
	int *left, *right;

	if (!array || size <= 1)
		return;

	left = allocate_slice(LEFT_SIZE(size));
	right = allocate_slice(RIGHT_SIZE(size));

	slice_array(array, left, right, size);
	merge_sort(left, LEFT_SIZE(size));
	merge_sort(right, RIGHT_SIZE(size));

	merge_arrays(left, right, array, size);
}
