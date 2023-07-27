#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int benn(void);
/**
 * counting_sort - the main function
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: 0
 */

void counting_sort(int *array, size_t size)
{
	int max_val, min_val;
	size_t i, counting_size;
	int *counting_array;
	int *sorted_array;
	ssize_t y;
	bool is_sorted = true;

	if (!array || size < 2)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		if (array[i] < array[i - 1])
		{
			is_sorted = false;
			break;
		}
	}
	if (is_sorted)
	{
		return;
	}
	max_val = array[0];
	min_val = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_val)
		{
			max_val = array[i];
		}
		if (array[i] < min_val)
		{
			min_val = array[i];
		}
	}
	if (max_val == min_val)
	{
		return;
	}
	
	counting_size = max_val - min_val + 1;
	counting_array = malloc(counting_size * sizeof(int));
	if (!counting_array)
	{
		return;
	}
	for (i = 0; i < counting_size; i++)
	{
		counting_array[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		counting_array[array[i] - min_val]++;
	}
	for (i = 1; i < counting_size; i++)
	{
		counting_array[i] += counting_array[i - 1];
	}
	sorted_array = malloc(size * sizeof(int));
	if (!sorted_array)
	{
		free(counting_array);
		return;
	}
	for (y = size - 1; y >= 0; y--)
	{
		sorted_array[counting_array[array[y] - min_val] - 1] = array[y];
		counting_array[array[y] - min_val]--;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = sorted_array[i];
	}
	free(counting_array);
	free(sorted_array);
}

/**
 * benn - main func
 * Return: 0
 */

int benn(void)
{
	return (0);
}
