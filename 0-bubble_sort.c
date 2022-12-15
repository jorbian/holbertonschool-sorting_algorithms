#include "sort.h"

/**
 * bubble_sort - sorts an array of integers via bubble sort
 * @array: array to be sorted
 * @size: size of the array
 *
 * Description: recursively sorts an array from least to greatest.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long i = 0;
	int switch_was_made = FALSE;
	int current_value[2];

	if (!array || size < 2)
		return;

	for (i = 0; (i <= size - 2); i++)
	{
		current_value[0] = array[i];
		current_value[1] = array[i + 1];

		if (current_value[0] > current_value[1])
		{
			switch_was_made = TRUE;
			array[i] = current_value[1];
			array[i + 1] = current_value[0];
			print_array(array, size);
		}
	}

	if (switch_was_made)
		bubble_sort(array, size);
}
