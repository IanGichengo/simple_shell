#include "shell.h"

/**
 * read_line - Read a line from the user
 * Return: The entered line as a string
 */

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		else
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
	}

	if (line[read - 1] == '\n')
	{
		line[read - 1] = '\0';
	}

	return (line);
}

/**
 * parse_line - Parse a line into arguments
 * @line: The input line
 *
 * Return: Array of tokens
 */

char **parse_line(char *line)
{
	int bufsize = 64;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " ");

	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("hsh");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " ");
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * handle_signal - Signal handler for Ctrl+C
 * @signal: The signal number
 */
void handle_signal(int signal)
{
	(void)signal;
	printf("\n($) ");
	fflush(stdout);
}
