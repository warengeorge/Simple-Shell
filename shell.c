#include "shell.h"

/**
 * interactiveShell - processes all interactive shell commands
 * @genHead: general struct
 * Return: Always 0.
 */
int interactiveShell(general_t *genHead)
{
	char **bufferTokens = NULL, *buffer = NULL;
	char *tmp = NULL;
	size_t len;

	while (1)
	{
		genHead->nCommands++;
		printPrompt("($) ");
		buffer = getUserInput(buffer, &len, genHead);
		bufferTokens = parseBuffer(buffer, genHead);
		findBuiltin(genHead, bufferTokens[0]);
		if (correctAbsPath(bufferTokens[0]))
			createFork(bufferTokens, genHead);
		else
		{
			tmp = findCmd(bufferTokens[0]);
			if (tmp)
				bufferTokens[0] = tmp;
			createFork(bufferTokens, genHead);
		}
	}
	freeStruct(genHead);
	return (0);
}

/**
 * nonInteractiveShell - process user commands in non-interactive mode
 * @buffer: input from the command line
 * @genHead: general struct
 * Return: Always 0.
 */
int nonInteractiveShell(char *buffer, general_t *genHead)
{
	char **bufferTokens;
	char *tmp;

	genHead->nCommands++;
	bufferTokens = parseBuffer(buffer, genHead);
	findBuiltin(genHead, bufferTokens[0]);
	if (correctAbsPath(bufferTokens[0]))
		createFork(bufferTokens, genHead);
	else
	{
		tmp = findCmd(bufferTokens[0]);
		if (tmp)
			bufferTokens[0] = tmp;
		createFork(bufferTokens, genHead);
	}
	return (0);
}
