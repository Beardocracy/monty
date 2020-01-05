#include "monty.h"

/**
 * get_instructions - returns a function pointer.
 * Return: pointer to first member of the array.
 */
void (*get_instructions(void))(stack_t **, unsigned int)
{
	char *command;
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
		{"pchar", pchar_op},
		{"pstr", pstr_op},
		{"rotl", rotl_op},
		{"rotr", rotr_op},
		{"stack", stack_op},
		{"queue", queue_op},
		{NULL, NULL}
	};

	if (get_global()->command == NULL)
	{
		return (nop_op);
	}
	else
	{
		command = get_global()->command;
		if (command[0] == '#')
			return (nop_op);
		for (i = 0; instructs[i].opcode != NULL; i++)
		{
			if (strcmp(command, instructs[i].opcode) == 0)
				return (instructs[i].f);
		}
	}
	return (NULL);
}
