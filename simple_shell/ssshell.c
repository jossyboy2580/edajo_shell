#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

/**
 * interactive_mode - This mode is activated when the program is called with no
 * arguments of command piped to it
 *
 * @env: This is the array of environment variables
 *
 * Return: 1 always
 */

int interactive_mode(char **av, char **env)
{
	int keep_running = 1;
	char *command = NULL;
	size_t n;
	char *valid_command;
	ssize_t nread;
	char **args;

	while (keep_running == 1)
	{
		printf("($) ");
		fflush(stdout);
		nread = _getline(&command, &n, stdin);
		if (nread == -1)
		{
			return (-1);
		}
		rmv_nwline(command);
		args = _strtok(command, " ");
		valid_command = validate_command(args[0], env);
		if (valid_command)
		{
			args[0] = valid_command;
			printf("%s: ", av[0] + 1);
			fflush(stdout);
			run_command(args, env, &keep_running);
		}
		else
		{
			printf("Command is invalid!\n");
		}
	}

}

/**
 * non_interactive_mode - This mode is activated if a command is piped into the program
 *
 * @env: The environment variables to use
 *
 * Return: 1 always
 */

int non_interactive_mode(char **av, char **env)
{
	char buffer[BUFFER_SIZE];
	ssize_t terminal_read;
	int keep_running = 0;
	char *valid_command;
	char **args;


	terminal_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	if (terminal_read > 0)
	{
		rmv_nwline(buffer);
		args = _strtok(buffer, " ");
		valid_command = validate_command(args[0], env);
		if (valid_command)
		{
			args[0] = valid_command;
			printf("%s: ", av[0] + 1);
			fflush(stdout);
			run_command(args, env, &keep_running);
		}
		else
		{
			printf("Is not valid");
		}
	}
	return (1);

}

/**
 * file_input_mode - This mode is activated if a file was sent to the program
 *
 * @filename: The name of the file
 * @env: list of environment variables
 *
 * Return: 1 on success
 */

int file_input_mode(char *filename, char **env)
{
	/**
	 * Open file
	 * read lines
	 * run exec on each lines
	 */
	return (1);

}

/**
 * main - The entry point of the shell program
 *
 * @ac: Number of arguments this program was invoked with
 * @av: Array of arguments in strings that this program was invoked with
 * @env: Array of environment variables
 *
 * Return: 0 on success always
 */

int main(int ac, char **av, char **env)
{
	/* Non-interactive Mode */
	if (!isatty(STDIN_FILENO))
	{
		non_interactive_mode(av, env);
	}
	else if (ac == 2)
	{
		/* File input mode */
		file_input_mode(av[1], env);
	}
	else
	{
		/* interactive mode */
		interactive_mode(av, env);
	}
	return (0);
}
