#include "shell.h"
/**
 * prompt_user - Fuction prototype
 * Description: Asks user for input infinitely.
 * **/
void prompt_user(void)
{
	static int first_time = 1;

	if (first_time)
	{
		const char  *CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J";

		write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
		first_time = 0;
	}
	write(1, "($) ", 4);
}
