#include "monty.h"

/**
 * swap_op - swaps the top two elements of the stack.
 * @head: pointer to a stack_t struct.
 * @line_number: the line of the file we are in.
 */
void swap_op(stack_t **head, unsigned int line_number)
{
	stack_t *ntemp;
	stack_t *temp = *head;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
				line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	ntemp = temp->next;
	(*head)->next = ntemp->next;
	(*head)->prev = ntemp;
	ntemp->prev = NULL;
	ntemp->next = temp;
	*head = ntemp;
}

/**
 * add_op - adds the top two elements of the stack.
 * @head: pointer to a stack_t struct.
 * @line_number: the line of the file we are in.
 */
void add_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
				line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n += (*head)->n;
	temp->prev = NULL;
	free(*head);
	*head = temp;
}

/**
 * sub_op - subtracts the top element from the second element of the stack.
 * @head: pointer to a stack_t struct.
 * @line_number: the line of the file we are in.
 */
void sub_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
				line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->n - (*head)->n;
	temp->prev = NULL;
	free(*head);
	*head = temp;
}

/**
 * div_op - divides the top element from the second element of the stack.
 * @head: pointer to a stack_t struct.
 * @line_number: the line of the file we are in.
 */
void div_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
				line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n",
				line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->n / (*head)->n;
	temp->prev = NULL;
	free(*head);
	*head = temp;
}

/**
 * mul_op - subtracts the top element from the second element of the stack.
 * @head: pointer to a stack_t struct.
 * @line_number: the line of the file we are in.
 */
void mul_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
				line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->n * (*head)->n;
	temp->prev = NULL;
	free(*head);
	*head = temp;
}
