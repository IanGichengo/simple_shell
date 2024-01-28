#include "shell.h"

/**
 * main - entry point
 * Return: returns 'EXIT_SUCCESS' when successful
 */

int main(void)
{
	char *line;
	char **args;
	int status;

	signal(SIGINT, handle_signal);

	do {
		printf("($) ");
		line = read_line();
		args = parse_line(line);
		status = execute_command(args);

		free(line);
		free(args);

	} while (status);

	return (EXIT_SUCCESS);
}
