#include "monty.h"

/**
 * get_instructions - returns a function pointer.
 * Return: pointer to first member of the array.
 */
void (*get_instructions(void))(stack_t **, unsigned int)
{
	char *command = get_global()->command;
	unsigned int i;
	instruction_t instructs[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"nop", nop_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{NULL, NULL}
	};

	for (i = 0; instructs[i].opcode != NULL; i++)
	{
		if (strcmp(command, instructs[i].opcode) == 0)
			return (instructs[i].f);
	}

	return (NULL);
}
