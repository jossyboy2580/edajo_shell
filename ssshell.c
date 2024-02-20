#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

void rmv_nwline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
}

int main(void)
{
	pid_t child;
	int keep_running = 1;
	int status;
	char *command = NULL;
	size_t n;
	ssize_t nread;
	char **args;

	while (keep_running == 1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		nread = _getline(&command, &n, stdin);
		if (nread == -1)
		{
			return (-1);
		}
		rmv_nwline(command);
		args = _strtok(command, " ");
		child = fork();
		if (child == -1)
			return (-1);
		if (child == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				perror("Error:");
		}
		else
		{
			wait(&status);
			if (strcmp(args[0], "exit") == 0)
				keep_running = 0;
		}
	}
}
