#include "shell.h"

/**
 * findBuiltin - find if command is a builtin
 * @genHead: general struct
 * @cmd: command to check
 * Return: run function if command is a builtin
 */
void findBuiltin(general_t *genHead, char *cmd)
{
	int i = 0;
	builtins_t *b = genHead->builtins;

	while (b[i].command)
	{
		if (_strcmp(cmd, b[i].command) == 0)
			b[i].f(genHead);
		i++;
	}
}

/**
 * initBuiltins - initialize Builtin struct
 * @genHead: general struct
 * Return: initialized builtin struct
 */
builtins_t *initBuiltins(general_t *genHead)
{
	int numCommands = 5;
	builtins_t *b;

	b = malloc(numCommands * sizeof(builtins_t));
	if (b == NULL)
		return (NULL);
	addMemBuiltins(genHead, b);

	b[0].command = "env";
	b[0].f = runEnv;
	b[1].command = "exit";
	b[1].f = runExit;
	b[2].command = "setenv";
	b[2].f = runSetenv;
	b[3].command = "unsetenv";
	b[3].f = runUnsetenv;
	b[4].command = NULL;
	b[4].f = NULL;
	return (b);
}
