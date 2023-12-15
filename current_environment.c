#include <stdio.h>

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

/**
 * main - The main function for the env built-in command.
 *
 * Return: Always 0.
 */
int main(void)
{
	char **env_vars = environ;

	printf("Current environment:\n");
	print_environment(env_vars);

	return (0);
}
