#include "shell.h"
int _execute(char * * args) {
	pid_t iid;
	int stat;

	if (strcmp(args[0], "exit") == 0)
		{
			return _exit();
		}
iid = fork();

	if (iid == 0) {
		if (execvp(args[0], args) < 0)
			printf("dash: command not found: %s\n", args[0]);
		exit(EXIT_FAILURE);

	} else if (iid < 0)
		printf(TIME "Error forking"
		 STARTAGAIN "\n");
	else {
		waitpid(iid, & stat, WUNTRACED);
	}

	return 1;
}
