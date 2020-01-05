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

/**
 * pchar_op - prints the n value in the top node of the stack as ascii, if ok.
 * @head: pointer to the head of the stack
 * @line_number: the line of the file.
 */
void pchar_op(stack_t **head, unsigned int line_number)
{
	int n;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
				line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	n = (*head)->n;
	if (n < 0 || n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
				line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", n);
}

/**
 * pstr_op - prints the string from at the top of the stack, followed by NL.
 * @head: pointer to the head of the stack
 * @line_number: the line of the file.
 */
void pstr_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int n;
	(void)line_number;

	if (*head != NULL)
		temp = *head;
	while (temp != NULL)
	{
		n = temp->n;
		temp = temp->next;
		if (n < 1 || n > 127)
			break;
		printf("%c", n);
	}
	printf("\n");
}

/**
 * rotl_op - Moves the top element to the back.
 * @head: pointer to the head of the stack
 * @line_number: the line of the file.
 */
void rotl_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *tail;
	(void)line_number;

	if (*head == NULL || (*head)->next == NULL)
		nop_op(head, line_number);
	else
	{
		temp = *head;
		tail = temp;
		*head = (*head)->next;
		(*head)->prev = NULL;
		while (tail->next)
			tail = tail->next;
		tail->next = temp;
		temp->prev = tail;
		temp->next = NULL;
	}
}
/**
 * rotr_op - Moves the last element to the top.
 * @head: pointer to the head of the stack
 * @line_number: the line of the file.
 */
void rotr_op(stack_t **head, unsigned int line_number)
{
	stack_t *tail, *temp;
	(void)line_number;

	if (*head == NULL || (*head)->next == NULL)
		nop_op(head, line_number);
	else
	{
		tail = *head;
		while (tail->next)
			tail = tail->next;
		temp = tail->prev;
		temp->next = NULL;
		tail->next = *head;
		(*head)->prev = tail;
		*head = tail;
	}
}
