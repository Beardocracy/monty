#include "monty.h"

/**
 * remove_newlines - replaces \n characters with spaces.
 * @s: a string
 */
void remove_newlines(char *s)
{
	int i;

	if (s == NULL)
		return;
	for (i = 0; s[i]; i++)
	{
		if (s[i] == '\n')
			s[i] = ' ';
	}
}

/**
 * free_everything - frees all malloc'd data.
 */
void free_everything(void)
{
	stack_t *temp;

	fclose(get_global()->fd);
	if (get_global()->line_save != NULL)
		free(get_global()->line_save);
	while (get_global()->top != NULL)
	{
		temp = get_global()->top->next;
		free(get_global()->top);
		get_global()->top = temp;
	}
}
