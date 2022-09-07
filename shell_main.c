#include "shell.h"

/**
 * main - 
 * Return: 0 on success or error on code.
 */

int main(void)
{
	char cmd[100], command[100], *parameters[20];
	char *envp[] = {(char *) "PATH=/bin", 0};

	while (1)
	{
		prompt_user();
		read_command(command, parameters);

		if (fork() != 0)
			wait(NULL);
		else
		{
			strcpy(cmd, "/bin/");
			strcat(cmd, command);
			if (execve(cmd, parameters, envp) == -1)
				perror("Command does not exist");
		}
		if (strcmp(command, "exit") == 0)
		{
			break;
		}
	}

	return (0);
}
