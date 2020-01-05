#include "monty.h"

/**
 * e_instructions - prints an error message for an invalid instruction.
 */
void e_instructions(void)
{
	fprintf(stderr, "L%u: unkown instruction %s\n",
			get_global()->line_number, get_global()->command);
	free(get_global()->command);
	exit(EXIT_FAILURE);
}

/**
 * e_value - prints an error message for attempting to push a non integer.
 */
void e_value(void)
{
	fprintf(stderr, "L%u: usage: push integer\n",
			get_global()->line_number);
	free_everything();
	exit(EXIT_FAILURE);
}
