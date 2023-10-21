#include "monty.h"
/**
* free_stack  - free the doubly linked list
* @head: A pointer to the stack's head.
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
