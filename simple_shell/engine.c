#include "main.h"

/**
 * run_command - A function that creates a process and runs a command
 *
 * @args: An argument array, list of strings
 * @env: The list of environment variables
 * @keep_running: Address of a keep running flag
 */

void run_command(char **args, char **env, int *keep_running)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
		return;
	if (child == 0)
	{
		if (execve(args[0], args, env) == -1)
			perror("Error:");
	}
	else
	{
		wait(&status);
		if (strcmp(args[0], "exit") == 0)
			*keep_running = 0;
	}
}
