#include "monty.h"

/**
 * remove_newlines - replaces \n characters with spaces.
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
	return;
}
