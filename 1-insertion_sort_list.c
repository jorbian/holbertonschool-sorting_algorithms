#include "sort.h"

/**
 * insertion_sort_list - Uses the insertion algorithm to sort a list
 * @list: a list
 * Return: nothing
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;
	int n;

	if (!list)
	return;
	tmp = *list;
	while (tmp)
	{
		while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				n = tmp->n;
				*(int *)&tmp->n = tmp->next->n;
				*(int *)&tmp->next->n = n;
				tmp = *list;
				print_list(*list);
				break;
			}

		}
		tmp = tmp->next;
	}
}
}
