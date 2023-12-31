#include "shell.h"

/**
 * print_environment - Prints the current environment variables.
 * @env_vars: The array of environment variables.
 */
void print_environment(char **env_vars)
{
	while (*env_vars != NULL)
	{
		printf("%s\n", *env_vars);
		env_vars++;
	}
}
