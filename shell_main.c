#include "shell.h"

/**
 * main - intepretes inputs ands arguments
 * @argc: number of arguments sent to main program
 * @argv: string of input from users
 * @env: shell environment variables
 * Return: Always 0
 */
int main(int argc, char **argv, char **env)
{
	char *buf;
	ssize_t charsRead;
	general_t *genHead = NULL;

	argc = argc;
	argv = argv;

	genHead = initStruct(env);
	initBuiltins(genHead);

	if (isatty(STDIN_FILENO))
	{
		genHead->isInteractive = 1;
		interactiveShell(genHead);
	}
	else
	{
		buf = malloc(1024 * sizeof(char));
		if (buf == NULL)
			exit(12);
		addMemNIBuffer(genHead, buf);
		charsRead = read(0, buf, 1024);
		if (charsRead == -1)
			exit(EXIT_FAILURE);
		else
		{
			genHead->isInteractive = 0;
			nonInteractiveShell(buf, genHead);
		}
	}
	return (0);
}
