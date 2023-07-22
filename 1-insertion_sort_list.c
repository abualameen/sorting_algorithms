#include "sort.h"
/**
 * insertion_sort_list - this function entry point
 * @list: the doubly linked list to be sorted
 * Return: void
 */



void insertion_sort_list(listint_t **list)
{
	listint_t *latest;

	if (!list || !(*list) || !((*list)->next))
	{
		return;
	}
	latest = (*list)->next;
	while (latest)
	{
		while (latest->prev && latest->n < latest->prev->n)
		{
			if (latest->next)
			{
				latest->next->prev = latest->prev;
			}
			latest->prev->next = latest->next;
			latest->next = latest->prev;
			latest->prev = latest->prev->prev;
			if (latest->prev)
			{
				latest->prev->next = latest;
			}
			else
			{
				(*list) = latest;
			}
			latest->next->prev = latest;
			print_list(*list);
		}
		latest = latest->next;
	}
}
