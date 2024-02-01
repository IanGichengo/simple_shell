#include "shell.h"

/**
 * execute_command - executes a command
 * @args: arguments array
 * Return: 1 on success 0 on failure
 */

int execute_command(char **args)
{
	pid_t pid, wpid;
	int status;

	if (args == NULL || args[0] == NULL)
		return (1);

	if (is_builtin(args[0]))
		return (hsh_exit(args) || hsh_env(args));

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("hsh");
		}
		exit(EXIT_FAILURE);
	}

	else if (pid < 0)
	{
		perror("hsh");
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
