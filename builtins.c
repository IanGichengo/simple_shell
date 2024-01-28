#include "shell.h"

/**
 * hsh_exit - Builtin exit command
 */

int hsh_exit(char **args)
{
	(void)args;
	exit(EXIT_SUCCESS);
}

/* Builtin env command */
int hsh_env(char **args)
{
	char *const envp[] = {NULL};

	(void)args;
	if (fork() == 0)
	{
		if (execve("/usr/bin/env", args, envp) == -1)
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}

	return (1);
}

/* Check if a command is a builtin */
int is_builtin(char *command)
{
	if (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0)
	{
		return (1);
	}
	return (0);
}
