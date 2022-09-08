#include "shell.h"

char * _getline() {
	int buffsize = 1024;
	int position = 0;
	char * buffer = malloc(sizeof(char) * buffsize);
	int i;

	if (!buffer) {
		fprintf(stderr, "%sdash: Allocation error%s\n", TIME, STARTAGAIN);
		exit(EXIT_FAILURE);
	}

	while (1) {
		i = getchar();
		if (i == EOF || i == '\n') {
			//printf("\n");
			buffer[position] = '\0';
			return buffer;
		} else {
			buffer[position] = i;
		}
		position++;

		if (position >= buffsize) {
			buffsize += 1024;
			buffer = realloc(buffer, buffsize);

			if (!buffer) {
	fprintf(stderr, "dash: Allocation error\n");
	exit(EXIT_FAILURE);
			}
		}
	}
}
