#include "sort.h"
/**
 * selection_sort - function entry
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t g, h, index_min;
	int tempu;

	if (!array || size < 2)
	{
		return;
	}
	for (g = 0; g < size - 1; g++)
	{
		index_min = g;
		for (h = g + 1; h < size; h++)
		{
			if (array[h] < array[index_min])
			{
				index_min = h;
			}
		}
		if (index_min != g)
		{
			tempu = array[g];
			array[g] = array[index_min];
			array[index_min] = tempu;
			print_array(array, size);
		}
	}
}
