#include "sort.h"
int lomuto_partition(int *array, int low, int high);
void quick_sort_recursive(int *array, int low, int high);
/**
 * quick_sort - the quick sort function def
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: 0
 */

void quick_sort(int *array, size_t size)
{

        if (!array || size < 2)
        {
                return;
        }
        quick_sort_recursive(array, 0, size - 1);
}


/**
 * quick_sort_recursive - the recursive function for quick sorting
 * @array: the array to be sorted
 * @low: starting index of the partiion
 * @high: Ending index of the partition
 */

void quick_sort_recursive(int *array, int low, int high)
{
        int pivot_idx;

        if (low < high)
        {
                pivot_idx = lomuto_partition(array, low, high);
                quick_sort_recursive(array, low, pivot_idx - 1);
                quick_sort_recursive(array, pivot_idx + 1, high);
        }
}

/**
 * lomuto_partition - partition function for quick sort
 * @array: the array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * Return: 0
 */

int lomuto_partition(int *array, int low, int high)
{
        int pivot = array[high];
        int i = low - 1;
        int j, temp;
	size_t n;

	n = sizeof(array);
        for (j = low; j <= high - 1; j++)
        {
                if (array[j] < pivot)
                {
                        i++;
                        if (i != j)
                        {
                                temp = array[i];
                                array[i] = array[j];
                                array[j] = temp;
                                print_array(array, n + 2);
                        }
                }
        }
        if ((i + 1) != high)
        {
                temp = array[i + 1];
                array[i + 1] = array[high];
                array[high] = temp;
                print_array(array, n + 2);
        }
        return (i + 1);
}
