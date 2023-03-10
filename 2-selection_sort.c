#include "sort.h"

/**
 *  selection_sort - implementation of selection sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned long i, j, index_of_min;
	int temp_buff;

	if ((array == NULL) || (size < 2))
		return;

	for (i = 0; i < size - 1; i++)
	{
		index_of_min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index_of_min])
				index_of_min = j;
		}
		if (array[index_of_min] == array[i])
			continue;

		temp_buff = array[index_of_min];
		array[index_of_min] = array[i];
		array[i] = temp_buff;

		print_array(array, size);
	}
}
