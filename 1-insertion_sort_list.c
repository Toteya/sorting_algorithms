#include "sort.h"
/**
 * insertion_sort:sorts a list using insertion sort method
 * @list: pointer that stores 
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *position, *curr, *prev = NULL;

	position = *list;

	while(position != NULL)
	{
		curr = position;
		while(prev && curr->n < prev->n)
		{
			prev->next = curr->next;
			curr->prev = prev->prev;
			curr->next = prev;
			prev->prev = curr;
			
			if(prev->prev)
				(prev->prev)->next = curr;
			if(curr->next)
				(curr->next)->prev = prev;

			curr = curr->prev;
			if(curr->prev)
				prev = curr->prev;
			else
				*list = curr;
		}

		position = position->next;
	}
}
