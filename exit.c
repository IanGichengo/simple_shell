#include "shell.h"

/**
 * _strncpy - copies a string
 * @dest: destination string
 * @src: source string
 * @n: amount of characters to copy
 * Return: concatenated string
 */

char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;
	char *s = dest;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (s);
}

/**
 * _strncat - concatenates two strings
 * @dest: first string
 * @src: second string
 * @n: maximum amount of bytes used
 * Return: concatenated string
 */

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t i, j;
	char *s = dest;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; j < n && src[j] != '\0'; i++, j++)
		dest[i] = src[j];

	dest[i] = '\0';

	return (s);
}

/**
 * _strchr - locates character in a string
 * @s: string to be parsed
 * @c: character to look for
 * Return: pointer to the memory area s
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0' && *s != c)
		s++;

	return (*s == c ? s : NULL);
}
