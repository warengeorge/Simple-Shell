#include "shell.h"

/**
 *
 * Return: 0 on success, 1 on error, or error on code.
 */

int main()
{
	char cmd[100], command[100], *parameters[20];
	char *envp[] = {(char *) "PATH=/bin", 0};

	while (1)
	{
		type_prompt();
		read_command(command, parameters);
		if (fork() != 0)
			wait (NULL);
		else
		{
			strcpy(cmd, "/bin/");
			strcat(cmd, command);
			execve(cmd, parameters, envp);
		}
		if (strcmp(command,"exit") == 0)
		{
			break;
		}
	}

	return 0;
}

