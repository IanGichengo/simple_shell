#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 1024

/**
 * display_prompt - Display the shell prompt
 */

void display_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

/**
 * execute_command - Execute the given command
 * @command: Array of strings representing the command and its arguments
 */
void execute_command(char **command)
{
	if (command[0] == NULL)
		return;

	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
		return;

	if (execvp(command[0], command) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * main - the main function
 * Return: null
 */

int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *command[MAX_INPUT_LENGTH];
	int i;

	while (1)
	{
		display_prompt();
		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			printf("\nExiting the shell.\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		char *token = strtok(input, " ");

		i = 0;

		while (token != NULL)
		{
			command[i++] = token;
			token = strtok(NULL, " ");
		}
		command[i] = NULL;
		execute_command(command);
	}
	return (0);
}
