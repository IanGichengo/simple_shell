#include "shell.h"

/**
 * hsh_exit - Builtin exit command
 * @args: arguments array
 * Return: exits with success status
 */

int hsh_exit(char **args)
{
	(void)args;
	exit(EXIT_SUCCESS);
}

/**
 * hsh_env - builtin env command
 * @args: arguments array
 * Return: always returns 1
 */

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

/**
 * is_builtin - checks if a command is built in
 * @command: command to check
 * Return: 1 if the command is builtin, 0 otherwise
 */

int is_builtin(char *command)
{
	if (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0)
	{
		return (1);
	}
	return (0);
}
