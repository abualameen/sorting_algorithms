#include "sort.h"
/**
 * bubble_sort - this is the bubble sort function
 * @array: the arrat to be sorted
 * @size: the size of the array
 * Return: the sorted array
 */

void bubble_sort(int *array, size_t size)
{
        size_t i, j;
        int swaped, tempu;

        if (!array || size < 2)
                return;
        for (i = 0; i < size - 1; i++)
        {
                swaped = 0;
                for (j = 0 ; j < size - i -1; j++)
                {
                        if (array[j] > array[j + 1])
                        {
                                tempu = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = tempu;
                                print_array(array, size);
                                swaped = 1;
                        }
                }
                if (!swaped)
                {
                        break;
                }
        }
}
