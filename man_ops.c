#include "monty.h"

/**
 * push_op - pushes a new node onto the stack.
 * @head: pointer to the top of the stack AKA head
 * @line_number: the line we are at in the monty file.
 */
void push_op(stack_t **head, unsigned int line_number)
{
	stack_t *new;
	unsigned int val, i;
	char *val_string;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (get_global()->values == NULL)
		e_value();
	val_string = get_global()->values;
	for (i = 0; val_string[i]; i++)
	{
		if (val_string[i] < '0' || val_string[i] > '9')
			e_value();
	}
	val = atoi(val_string);
	new->n = val;
	new->next = *head;
	*head = new;
}

/**
 * pall_op - prints all the values on the stack, starting from the top.
 * @stack: pointer to the top of the stack.
 * @line_number: the current line number in the file.
 */
void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	(void)line_number;

	if (*stack == NULL)
		return;
	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
