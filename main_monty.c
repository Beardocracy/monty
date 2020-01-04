#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - main file for monty interpreter
 * @argc: the number of arguments
 * @argv: an array of strings. The arguments from the command line.
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
	void (*func)(stack_t **, unsigned int);
	FILE *monty_file = NULL;
	char *line = NULL;
	size_t len = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	get_global()->fd = monty_file;
	while (getline(&line, &len, monty_file) != -1)
	{
		remove_newlines(line);
		get_global()->line_save = line;
		get_global()->line_number += 1;
		get_global()->command = strtok(line, " ");
		get_global()->values = strtok(NULL, " ");
		func = get_instructions();
		if (func == NULL)
			e_instructions();
		func(&(get_global()->top), get_global()->line_number);
	}
	free_everything();
	return (EXIT_SUCCESS);
}
