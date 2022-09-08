#include "shell.h"

/**
 * addMemNIBuffer - Adds non-interactive buffer to gen struct
 * @genHead: The general variables struct
 * @buf: The non-interactive buffer
 *
 * Return: None
 */
void addMemNIBuffer(general_t *genHead, char *buf)
{
	if (genHead == NULL)
	{
		perror("addMemNIBuffer(): genHead empty");
		exit(EXIT_FAILURE);
	}
	if (buf == NULL)
	{
		perror("addMemNIBuffer(): buffer empty");
		exit(EXIT_FAILURE);
	}
	genHead->nonInteractiveBuffer = buf;
}

/**
 * addMemIBuffer - Adds interactive buffer to gen struct
 * @genHead: The general variables struct
 * @buf: The interactive buffer
 *
 * Return: None
 */
void addMemIBuffer(general_t *genHead, char *buf)
{
	if (genHead == NULL)
	{
		perror("addMemIBuffer(): genHead empty");
		exit(EXIT_FAILURE);
	}
	if (buf == NULL)
	{
		perror("addMemIBuffer(): buffer empty");
		exit(EXIT_FAILURE);
	}
	genHead->interactiveBuffer = buf;
}

/**
 * addMemEnv - Adds env double ptr to gen struct
 * @genHead: The general variables struct
 * @env: The environment passed in main
 *
 * Return: None
 */
void addMemEnv(general_t *genHead, char **env)
{
	if (genHead == NULL)
	{
		perror("addMemEnv(): genHead empty");
		exit(EXIT_FAILURE);
	}
	if (env == NULL)
	{
		perror("addMemEnv(): env empty");
		exit(EXIT_FAILURE);
	}
	genHead->_env = env;
}

/**
 * addMemBufferTokens - Adds buffer tokens to gen struct
 * @genHead: The general variables struct
 * @tokens: The buffer tokens
 *
 * Return: None
 */

void addMemBufferTokens(general_t *genHead, char **tokens)
{
	if (genHead == NULL)
	{
		perror("addMemBufferTokens(): genHead empty");
		exit(EXIT_FAILURE);
	}
	if (tokens == NULL)
	{
		perror("addMemBufferTokens(): tokens empty");
		exit(EXIT_FAILURE);
	}
	if (tokens != NULL)
		freeBufferTokens(genHead);
	genHead->bufferTokens = tokens;
}

/**
 * addMemBuiltins - Adds builtins struct to gen struct
 * @genHead: The general variables struct
 * @builtins: The builtins struct
 *
 * Return: None
 */
void addMemBuiltins(general_t *genHead, builtins_t *builtins)
{
	if (genHead == NULL)
	{
		perror("addMemBuilins(): genHead empty");
		exit(EXIT_FAILURE);
	}
	if (builtins == NULL)
	{
		perror("addMemBuiltins(): builtins empty");
		exit(EXIT_FAILURE);
	}
	genHead->builtins = builtins;
}
