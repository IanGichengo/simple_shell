#include <stdio.h>
#include <string.h>

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

/**
 * main - The main function for the example program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char input[] = "This,is,a,sample,string";
	char *save_ptr = NULL;

	printf("Original string: %s\n", input);

	char *token = find_next_token(input, ',', &save_ptr);

	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = find_next_token(NULL, ',', &save_ptr);
	}
	return (0);
}
