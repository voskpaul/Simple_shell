#include "shell.h"

/**
 * get_sigint - for Handling the crtl + c call in prompt
 * @sig: for Signal handler.
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
