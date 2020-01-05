#include "monty.h"

/**
 * stack_op - sets the queue variable to 0.
 * @head: struct_t pointer to the first node of LL
 * @line_number: the current line number in the file
 */
void stack_op(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	get_global()->queue = 0;
}

/**
 * queue_op - sets the queue variable to 1.
 * @head: struct_t pointer to the first node of LL
 * @line_number: the current line number in the file
 */
void queue_op(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	get_global()->queue = 1;
}
