#include "shell.h"

/**
 * __strcat - Concatenate two strings
 * @dest: The string to concat to
 * @src: The string to add from
 * Return: Pointer to dest string
 */
char *__strcat(char *dest, char *src)
{
	int len = 0;
	int i;

	while (dest[len])
	{
		len++;
	}
	for (i = 0; src[i]; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i + 1] = '\0';
	return (dest);
}

/**
 * _strlen - Computes length of string
 * @str: The string
 *
 * Return: Length
 *
 */
unsigned int _strlen(const char *str)
{
	unsigned int length = 0;

	if (!str)
		return (0);
	for (length = 0; str[length]; length++)
		;
	return (length);
}

/**
 * _strcmp - compares 2 strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: - 0 if same or integer of (s1[i] - s2[i]) otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0')
			return (0);
	}
	return (s1[i] - s2[i]);
}

/**
 * _strcpy - Copies one string to another
 * @dest: The string to copy to
 * @src: The string to copy from
 *
 * Return: The dest string
 */
void _strcpy(char *dest, char *src)
{
	unsigned int i;

	if (dest == NULL || src == NULL)
		return;
	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}
