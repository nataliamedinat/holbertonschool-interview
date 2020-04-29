#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - Function that inserts a number in a linked list
 * @head : double pointer to the head node
 * @number: Number to insert
 * Return: Address to the new node or null if it fails.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
	return (NULL);
	}

	new_node->n = number;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
