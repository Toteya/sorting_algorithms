#include "sort.h"
/**
 * insertion_sort:sorts a list using insertion sort method
 * @list: pointer that stores 
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *position, *curr, *prev = NULL;

	if (!list)
		return;

	position = *list;

	while(position != NULL)
	{
		curr = position;
		prev = curr->prev;
		while(prev && curr->n < prev->n)
		{
			prev->next = curr->next;
			curr->prev = prev->prev;
			if(prev->prev)
				(prev->prev)->next = curr;
			if(curr->next)
				(curr->next)->prev = prev;
			curr->next = prev;
			prev->prev = curr;
			
			prev = curr->prev;
			if (!prev)
				*list = curr;

			print_list(*list);
		}

		position = position->next;
	}
}
