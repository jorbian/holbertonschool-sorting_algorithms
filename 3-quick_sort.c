#include "sort.h"

/**
 * quick_sort - function that uses the quick sort algorithm
 * @array: an array
 * @size: size of the array
 * Return: nothing
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - partiton
 * @array: an array
 * @lo: lower
 * @hi: higher
 * @size: size of the array
 * Return: 1
*/
int partition(int *array, int lo, int hi, size_t size)
{
	int i = lo - 1, j = lo;
	int pivot = array[hi], aux = 0;

	for (; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[hi])
	{
		aux = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = aux;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_s - quick sort
 * @array: an array
 * @lo: lower
 * @hi: higher
 * @size: size of the array
 * Return: nothing
*/
void quick_s(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quick_s(array, lo, pivot - 1, size);
		quick_s(array, pivot + 1, hi, size);
	}
}
