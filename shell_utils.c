#include "shell.h"

/**
 * getUserInput - gets user input from shell
 * @buffer: where user's input is stored
 * @length: length of user's input
 * @genHead: general struct
 * Return: pointer to user's input line
 */
char *getUserInput(char *buffer, size_t *length, general_t *genHead)
{
	ssize_t chars_read;

	chars_read = getline(&buffer, length, stdin);
	if ((chars_read == -1) && (!buffer))
	{
		perror("Invalid argument");
		exit(EXIT_FAILURE);
	}
	else if (chars_read == -1 && buffer)
	{
		buffer[0] = '\n';
		write(1, buffer, 1);
		freeEnv(genHead);
		freeBuiltins(genHead);
		free(genHead);
		free(buffer);
		exit(0);
	}
	addMemIBuffer(genHead, buffer);
	return (buffer);
}

/**
 * parseBuffer - parse user's input
 * @buffer: user's raw input
 * @genHead: main struct for vars
 * Return: tokenized string of user's input
 */
char **parseBuffer(char *buffer, general_t *genHead)
{
	char *delim = " \t\r\n";
	char **tokens = tokenize(buffer, delim, genHead);

	return (tokens);
}

/**
 * correctAbsPath - process command if correct info was entered by user
 * @token: raw user input
 * Return: Always 0.
 */
size_t correctAbsPath(char *token)
{
	struct stat st;

	if (stat(token, &st) == 0)
		return (1);
	return (0);
}

/**
 * tokenize - tokenize raw user's data
 * @str: user's raw data
 * @delim: delimiters for user's raw input
 * @genHead: general struct
 * Return: string of tokens from users input
 */
char **tokenize(char *str, char *delim, general_t *genHead)
{
	char *current;
	char **tokens;
	int i = 0;

	current = strtok(str, delim);
	tokens = malloc(NUM_TOKENS * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	addMemBufferTokens(genHead, tokens);
	for (i = 0; i < NUM_TOKENS; i++)
	{
		tokens[i] = malloc(100 * sizeof(char));
		if (tokens[i] == NULL)
		{
			if (i != 0)
				i -= 1;
			for (; i >= 0; i--)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
	}
	i = 0;
	while (current)
	{
		if (i > 0)
			current = strtok(NULL, delim);
		free(tokens[i]);
		tokens[i] = current;
		i++;
	}
	for (; i < NUM_TOKENS; i++)
		free(tokens[i]);
	return (tokens);
}
