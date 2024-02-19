#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
	pid_t child;
	int keep_running = 1;
	char *command;
	size_t n;
	ssize_t nread;

	while (keep_running)
	{
		if (_getline(&command, &n, stdin) == -1)
		{
			return (-1);
		}
		-- make an argument vector;
		-- create a child process;
		-- run the vommand in the child process;
		-- repeat that until an unknown command is entered;
		-- you stop the program by changing the status of the keep_running flag;
	}
}
