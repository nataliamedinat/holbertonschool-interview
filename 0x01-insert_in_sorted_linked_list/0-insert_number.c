#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - Inserts a node in numerical order into a linked list
 * @head: Double pointer to the head node
 * @number: Number to insert
 * Return: Null if failed - Otherwise pointer to the new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *current;

	if (head == NULL || *head == NULL)
		return(add_nodeint_end(head, number));

	current = *head;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;
	if (number < current->n)
	{
		new_node->next = current;
		*head = new_node;
		return(new_node);
	}

	while (current->next != NULL && current->next->n < new_node->n)
		current = current->next;

	new_node->next = current->next;
	current->next = new_node;

	return (new_node);

}
