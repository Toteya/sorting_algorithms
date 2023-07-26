#include "deck.h"
#include <stdlib.h>

void cocktail_sort_deck(deck_node_t **deck);
int compare(const card_t *cardA, const card_t *cardB);
void swap_nodes(deck_node_t *left, deck_node_t *right);
int get_card_value(const char *value);

/**
 * sort_deck - Sorts a deck of cards
 * @deck: The deck to be sorted
 *
 * Return: Nothing.
 */
void sort_deck(deck_node_t **deck)
{
	cocktail_sort_deck(deck);
}



/**
 * cocktail_sort_deck - Sorts a deck of cards (doubly linked list) using the
 * cocktail sort algorithm
 * @deck: Double pointer to the the deck (first card in the deck) to be sorted
 *
 * Return: Nothing.
 */
void cocktail_sort_deck(deck_node_t **deck)
{
	deck_node_t *first, *last, *current;

	if (!deck || !(*deck))
		return;

	first = *deck;
	last = *deck;

	while (last->next)
		last = last->next;

	while (first != last && first->prev != last)
	{
		current = first;
		while (current != last && current->next != NULL)
		{
			if (compare(current->card, (current->next)->card) > 0)
			{
				swap_nodes(current, current->next);
				if ((current->prev)->prev == NULL)
					*deck = current->prev;
				if (current == first)
					first = current->prev;
				/* print_list(*deck); */
			}
			else
				current = current->next;
		}
		last = current->prev;
		current = last;

		while (current != first && current->prev != NULL)
		{
			if (compare(current->card, (current->prev)->card) < 0)
			{
				swap_nodes(current->prev, current);
				if (current->prev == NULL)
					*deck = current;
				if (current == last)
					last = current->next;
				/* print_list(*deck); */
			}
			else
				current = current->prev;
		}
		first = current->next;
	}
}

/**
 * compare - Compares two cards
 * @cardA: The first card
 * @cardB: The second card
 *
 * Return: comparison i.e. cardA - cardB
 */
int compare(const card_t *cardA, const card_t *cardB)
{
	if (cardA->kind == cardB->kind)
		return (get_card_value(cardA->value) - get_card_value(cardB->value));

	return (cardA->kind - cardB->kind);
}

/**
 * get_card_value - Returns the integer equivalent of a card's value
 * @value: A string of the card's value (Jack, Queen, A, 1;, 2, etc.)
 *
 * Return: The integer equivalent of the card's value
 */
int get_card_value(const char *value)
{
	int int_value;

	if (*value == 'K')
		int_value = 13;
	else if (*value == 'Q')
		int_value = 12;
	else if (*value == 'J')
		int_value = 11;
	else if (*value == 'A')
		int_value = 1;
	else if (value[1] == '0')
		int_value = 10;
	else
		int_value = *value - '0';
	return (int_value);
}

/**
 * swap_nodes - swaps the order of two nodes in a doubly-linke list
 * @left: The first node (prev of right)
 * @right: The second node (next of left)
 *
 * Return: Nothing
 * Description: Swap nodes: <left>-<right>  ==>  <right>-<left>
 */
void swap_nodes(deck_node_t *left, deck_node_t *right)
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
