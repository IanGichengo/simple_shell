#include <stdio.h>
#include <stdlib.h>

/**
 * exit_shell - Exits the shell with a message.
 */
void exit_shell(void)
{
	printf("Exiting the shell.\n");
	exit(0);
}

/**
 * main - The main function for the simple shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	char input[100];

	while (1)
	{
		printf("Shell> ");
		fgets(input, sizeof(input), stdin);

		if (strcmp(input, "exit\n") == 0)
		{
			exit_shell();
		}
		else
		{
			printf("You entered: %s", input);
		}
	}
	return (0);
}
