#include "shell.h"
#include "errno.h"

/**
 * runExit - runs exit routine
 * @genHead: general struct
 * Return: none
 */
void runExit(general_t *genHead)
{
	freeStruct(genHead);
	exit(0);
}

/**
 * findCmd - finds the command in the possible paths from the PATH env var
 * @b: buffer of entir PATH environment variable
 * Return: string that returns PATH concatenated with command if found
 */
char *findCmd(char *b)
{
	char *hshPath, *tmpPath, *token, *slash = "/", *t = NULL, *tmpToken;
	struct stat st;
	int count1 = 0;

	hshPath = _getenv(HSHPATH);
	tmpPath = malloc(_strlen(hshPath) * sizeof(char) + 1);
	if (tmpPath == NULL)
		return (NULL);
	tmpPath = __strcat(tmpPath, hshPath);
	tmpToken = malloc(_strlen(b) * sizeof(char) + 1);
	if (tmpToken == NULL)
		return (NULL);
	tmpToken = __strcat(tmpToken, b);
	token = strtok(tmpPath, "="); /*remove PATH text*/
	for (token = strtok(NULL, ":"); token != NULL; token = strtok(NULL, ":"))
	{
		count1 = _strlen(token) + _strlen(slash) + _strlen(b) + 1;
		t = malloc(count1 * sizeof(char));
		if (t == NULL)
			return (NULL);
		t = __strcat(t, token);
		t = __strcat(t, slash);
		t = __strcat(t, b);
		if (stat(t, &st) == 0)
		{
			free(tmpPath);
			free(tmpToken);
			return (t);
		}
		free(t);
	}
	free(tmpPath);
	return (tmpToken);
}

/**
 * createFork - run the user's command with fork and execve
 * @bufferTokens: user's command properly formatted
 * @genHead: general struct
 * Return: Always 0
 */
int createFork(char **bufferTokens, general_t *genHead)
{
	pid_t child_pid;
	int status;
	char *tmp = NULL, *tmpNum = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		freeStruct(genHead);
		perror("fork: Resource temporarily unavailable");
		return (1);
	}
	tmp = malloc(500 * sizeof(char));
	if (tmp == NULL)
		perror("createFork:Could not malloc");
	tmp = __strcat(tmp, bufferTokens[0]);
	if (child_pid == 0)
	{
		if (execve(bufferTokens[0], bufferTokens, genHead->_env) == -1)
		{
			tmpNum = _itoa(genHead->nCommands);
			write(1, "hsh: ", 5);
			write(1, tmpNum, _strlen(tmpNum));
			write(1, ": ", 2);
			write(1, tmp, _strlen(tmp));
			write(1, ": not found\n", 12);
			free(tmp);
			free(tmpNum);
			freeStruct(genHead);
			exit(EXIT_FAILURE);
		}
		exit(0);
	}
	else
	{
		wait(&status);
		free(tmp);
	}
	return (0);
}

/**
 * freeEnv - free environment data struct
 * @genHead: pointer to main struct
 * Return: none
 */
void freeEnv(general_t *genHead)
{
	unsigned int i;

	for (i = 0; genHead->_env[i]; i++)
		free(genHead->_env[i]);
	free(genHead->_env);
}

/**
 * freeBufferTokens - Frees all buffer tokens
 * @genHead: Pointer to main struct
 *
 * Return: None
 */
void freeBufferTokens(general_t *genHead)
{
	unsigned int i;

	for (i = 0; genHead->bufferTokens && genHead->bufferTokens[i]; i++)
		free(genHead->bufferTokens[i]);
	if (genHead->bufferTokens)
		free(genHead->bufferTokens);
}

/**
 * freeBuffer - Frees interactive and non-interactive buffer
 * @buf: The char pointer(s) in gen struct
 *
 * Return: None
 */
void freeBuffer(char *buf)
{
	if (buf == NULL)
		return;
	free(buf);
}

/**
 * freeBuiltins - Frees all of the builtins
 * @genHead: The general struct
 *
 * Return: None
 */
void freeBuiltins(general_t *genHead)
{
	free(genHead->builtins);
}

/**
 * freeStruct - free main program general_t struct
 * @genHead: pointer to main struct
 * Return: none
 */
void freeStruct(general_t *genHead)
{
	if (genHead == NULL)
		return;
	freeEnv(genHead);
	freeBufferTokens(genHead);
	freeBuiltins(genHead);
	free(genHead);
}
