#include "sort.h"

#define ADJUST(r) (r - 1)

/**
 * get_range - calculate the numerical range of array we're sorting
 * @array: pointer to array of integers to be sorted
 * @size: how big the array is
 *
 * Return: whatever the largest number in the array was
*/
static size_t get_range(int *array, size_t size)
{
	size_t i;
	int range = 0;

	for (i = 0; i < size; i++)
		if (array[i] > range)
			range = array[i];

	return ((size_t)range + 1);
}

/**
 * initalize_count - initalizes the count array of each number
 * @range: the largest number we need to care about
 *
 * Return: pointer to a fresh count array
*/
static int *initalize_count(size_t range)
{
	int *new_count;

	new_count = malloc((range) * sizeof(int));
	if (new_count == NULL)
		return (NULL);

	memset(new_count, 0, range * sizeof(int));

	return (new_count);
}

/**
 * copy_result - copies the result of the counting sort into original array
 * @original: the original array we were sorting
 * @result: the results we're working with
 * @range: basically the overall size
*/
static void copy_result(int *original, int *result, size_t range)
{
	size_t i, j = 0;
	int tick = 0;

	for (i = 0; i <= ADJUST(range); ++i)
	{
		if (result[i] > tick)
		{
			original[j] = i;
			j++;
			tick++;
		}
		tick = result[i];
	}
}

/**
 * make_checker_count - populate the 'count_4_checker' back in main function
 * @ar: the original array we're sorting
 * @c: the 'count' array
 * @c4c: the 'count_4_checker'
 * @s: pointer to the size variable
 * @r: pointer to the range variable
*/
static void make_checker_count(int *ar, int *c, int *c4c, size_t *s, size_t *r)
{
	size_t i, j, k;
	size_t tick = 0;

	for (i = 0; i < (*r); i++)
	{
		if (!c[i])
			c4c[i] = tick;
		else
		{
			j = c[i];
			k = i;
			while (j > 0 && k != (*r))
			{
				tick++;
				c4c[k] = tick;
				j--;
				k++;
			}
			i = k - 1;
		}
	}
	if (tick == 1)
		c4c[ar[0]] = (*s);
}

/**
 * counting_sort - implementation of counting sort
 * @array: an array of positive integers to be sorted
 * @size: how many such integers there are
*/
void counting_sort(int *array, size_t size)
{
	int *our_count;
	int *count_4_checker;

	size_t i, range;

	if (size < 2 || !array)
		return;

	range = get_range(array, size);
	our_count = initalize_count(range);
	count_4_checker = initalize_count(range);

	for (i = 0; i < size; i++)
		our_count[array[i]]++;

	make_checker_count(
		array, our_count, count_4_checker, &size, &range
	);
	print_array(count_4_checker, ADJUST(range));

	copy_result(array, count_4_checker, range);

	free(our_count);
	free(count_4_checker);
}
