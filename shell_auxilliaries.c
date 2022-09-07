#include "shell.h"
/**
 * read_command - Function prototype
 * @cmd: Function argument to take command
 * @par: Function argument to take command
 * Description: Extract input from user
 * **/

void read_command(char cmd[], char *par[])
{
	char line[1024];
	int count = 0, i = 0, j = 0;
	char *array[100], *pch;

	for (;;)
	{
		int c = fgetc(stdin);

		line[count++] = (char) c;
		if (c == '\n')
			break;
	}
	if (count == 1)
		return;
	pch = strtok(line, "\n");

	while (pch != NULL)
	{
		array[i++] = strdup(pch);
		pch = strtok(NULL, "\n");
	}
	strcpy(cmd, array[0]);

	for (int j = 0; j < i; j++)
		par[j] = array[j];
	par[i] = NULL;
}
