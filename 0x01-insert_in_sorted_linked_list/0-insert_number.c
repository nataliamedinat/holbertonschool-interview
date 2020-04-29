#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */

listint_t *insert_node(listint_t **head, int number);
{
    listint_t *new_node;
    new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
	return (NULL);
	}
    new_node->number = number;
	new_node->next = *head;
	*head = new_node;
    return (new_node);
}
