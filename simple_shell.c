#include "shell.h"

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
