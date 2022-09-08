#include "shell.h"

/**
 * printPrompt - Prints the prompt
 * @prompt: The prompt to print
 *
 * Return: none
 */
void printPrompt(char *prompt)
{
	unsigned int length;

	length = _strlen(prompt);
	write(1, prompt, (size_t)length);
}

/**
 * initStruct - initial general struct
 * @env: environment data from shell
 * Return: initialized general struct
 */
general_t *initStruct(char **env)
{
	general_t *universal;
	int i = 0;
	unsigned int str_len;
	char **new_env;

	universal = malloc(sizeof(general_t));
	if (universal == NULL)
	{
		perror("main struct failed");
		return (NULL);
	}
	new_env = malloc(ENVSIZE * sizeof(char *));
	if (new_env == NULL)
	{
		perror("Environment malloc failed");
		exit(12);
	}
	addMemEnv(universal, new_env);
	while (env[i])
	{
		str_len = _strlen(env[i]);
		new_env[i] = malloc(++str_len * sizeof(char));
		if (new_env[i] == NULL)
		{
			if (i != 0)
				i--;
			for (; i >= 0; i--)
				free(new_env[i]);
			free(new_env);
			exit(12);
		}
		_strcpy(new_env[i], env[i]);
		i++;
	}
	universal->nCommands = 0;
	return (universal);
}

/**
 * _itoa - converts unsigned integer to alphanumeric
 * @num: number to convert to string
 * Return: text of number
 */
char *_itoa(unsigned int num)
{
	int divisor = 1, d, t, index = 0, highestorderdigit = 0;
	char *digits = NULL;

	if (num <= 0)
		return ("0");
	else if (num > 5000)
		return ("5000 is max");

	digits = malloc(5 * sizeof(char));
	if (digits == NULL)
		return (NULL);

	divisor = 1000;
	for (t = 0; t < 4; t++)
	{
		d = (num / divisor) % 10;
		if ((d != 0) && !highestorderdigit)
			highestorderdigit = 1;
		if (highestorderdigit)
		{
			digits[index++] = d + '0';
		}
		divisor = divisor / 10;
	}
	digits[index] = '\0';
	return (digits);
}
