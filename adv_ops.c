#include "monty.h"

/**
 * mod_op - subtracts the top element from the second element of the stack.
 * @head: pointer to a stack_t struct.
 * @line_number: the line of the file we are in.
 */
void mod_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
				line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->n % (*head)->n;
	temp->prev = NULL;
	free(*head);
	*head = temp;
}
