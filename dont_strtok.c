#include "shell.h"

/**
 * find_next_token - Finds the next token in a string.
 * @str: The input string.
 * @delimiter: The delimiter character.
 * @save_ptr: A pointer to save the current position in the string.
 * Return: A pointer to the next token or NULL if no more tokens are found.
 */

char *find_next_token(char *str, char delimiter, char **save_ptr)
{
	char *token_start = *save_ptr ? *save_ptr : str;
	char *token_end = strchr(token_start, delimiter);

	if (token_end != NULL)
	{
		*token_end = '\0';
		*save_ptr = token_end + 1;
		return (token_start);
	}
	else if (*token_start != '\0')
	{
		*save_ptr = NULL;
		return (token_start);
	}
	return (NULL);
}
