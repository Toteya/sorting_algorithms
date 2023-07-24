#include "sort.h"

void swap_nodes(listint_t *left, listint_t *right);

/**
 * cocktail_sort_list - Sorts a doubly linked list using the cocktail sort
 * algorithm
 * @list: Pointer to the head of the list to be sorted
 *
 * Return: Nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *first, *last, *current;

	if (!list || !(*list))
		return;

	first = *list;
	last = *list;

	while (last->next)
		last = last->next;

	while (first != last)
	{
		current = first;
		while (current != last && current->next != NULL)
		{
			if (current->n > (current->next)->n)
			{
				swap_nodes(current, current->next);
				if ((current->prev)->prev == NULL)
					*list = current->prev;
				print_list(*list);
			}
			else
				current = current->next;
		}
		last = current->prev;
		current = last;

		while (current != first && current->prev != NULL)
		{
			if (current->n < (current->prev)->n)
			{
				swap_nodes(current->prev, current);
				if (current->prev == NULL)
					*list = current;
				print_list(*list);
			}
			else
				current = current->prev;
		}
		first = current->next;
	}
}


/**
 * swap_nodes - swaps the order of two nodes in a doubly-linke list
 * @left: The first node (prev of right)
 * @right: The second node (next of left)
 *
 * Return: Nothing
 * Description: Swap nodes: <left>-<right>  ==>  <right>-<left>
 */
void swap_nodes(listint_t *left, listint_t *right)
{
	if (!left || !right)
		return;

	left->next = right->next;
	right->prev = left->prev;
	if (left->prev)
		(left->prev)->next = right;
	if (right->next)
		(right->next)->prev = left;
	right->next = left;
	left->prev = right;
}


