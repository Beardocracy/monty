#include "monty.h"

/**
 * get_global - returns a struct pointer.
 * Return: struct pointer.
 */
global_t *get_global(void)
{
	static global_t global = {
		0,
		0,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL
	};

	return (&global);
}
