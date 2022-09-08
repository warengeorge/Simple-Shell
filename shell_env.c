#include "shell.h"

/**
 * _getenv - Gets environment
 * @name: Name
 *
 * Return: The environment
 */
char *_getenv(char *name)
{
	int i = 0, j;
	char *token;

	token = strtok(&(environ[0][0]), "=");

	while (environ[i])
	{
		if (_strcmp(token, name) == 0)
		{
			for (j = 0; environ[i - 1][j]; j++)
				;
			environ[i - 1][j] = '=';
			return (environ[i - 1]);
		}
		token = strtok(&(environ[i][0]), "=");
		i++;
	}

	return (NULL);
}

/**
 * runEnv - Run the environment builtin
 * @genHead: The gen struct
 *
 * Return: None
 */
void runEnv(general_t *genHead)
{
	int i = 0;

	while (genHead->_env[i])
	{
		write(1, genHead->_env[i], _strlen(genHead->_env[i]));
		write(1, "\n", 1);
		i++;
	}
}

/**
 * runSetenv - Run setenv
 *
 * Return: None
 */
void runSetenv(void)
{
	write(1, "runSetenv\n", 10);
}

/**
 * runUnsetenv - Run setenv
 *
 * Return: None
 */
void runUnsetenv(void)
{
	write(1, "runUnsetenv\n", 12);
}
