#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * read_input - Read characters from standard input into a buffer
 * @buffer: input character
 * @size: input size
 * Return: The number of characters read.
 */
ssize_t read_input(char *buffer, size_t size)
{
	return (read(STDIN_FILENO, buffer, size));
}

/**
 * append_char - Append a character to a dynamically allocated string.
 * @str: string data input
 * @c: character data type
 * @size: input size
 * Return: A pointer to the updated string.
 */
char *append_char(char *str, char c, size_t *size)
{
	str = realloc(str, (*size) + 1);

	if (str == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	str[(*size)++] = c;
	return (str);
}

/**
 * custom_getline - Read a line of input from standard input.
 *
 * Return: A dynamically allocated string containing the line.
 */
char *custom_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static char *buffer_ptr = buffer;

	char *line = NULL;
	size_t line_size = 0;

	while (1)
	{
		if (remaining_chars == 0)
		{
			ssize_t read_chars = read_input(buffer, BUFFER_SIZE);

			if (read_chars <= 0)
				break;
			buffer_ptr = buffer;
			remaining_chars = (size_t)read_chars;
		}

		char current_char = *buffer_ptr++;

		remaining_chars--;

		if (current_char == '\n' || current_char == EOF)
			break;

		line = append_char(line, current_char, &line_size);
	}
	line = append_char(line, '\0', &line_size);
	return (line);
}

/**
 * main - The main function for the example program.
 *
 * This function prompts the user to enter a line of text, reads it using
 * custom_getline, and prints the entered text.
 *
 * Return: 0 on success.
 */
int main(void)
{
	printf("Enter a line of text: ");
	fflush(stdout);

	char *line = custom_getline();

	if (line != NULL)
	{
		printf("You entered: %s\n", line);
		free(line);
	}
	else
	{
		printf("Error reading input.\n");
	}
	return (0);
}
