#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t adjusted_size = 1;
	char buff;
	ssize_t status;
	int streamno = fileno(stream);

	printf("Stream no: %d\n", streamno);
	do {
		status = read(streamno, &buff, 1);
		if (status == -1)
		{
			dprintf(STDERR_FILENO, "Could'nt read this char");
			_exit(EXIT_FAILURE);
		}
		if (status == 0)
		{
			(*lineptr)[adjusted_size - 1] = '\0';
			return (-1);
		}
		*lineptr = realloc(*lineptr, sizeof(char) * ++adjusted_size);
		if (*lineptr)
			(*lineptr)[adjusted_size - 2] = buff;
	} while (buff != '\n');
	(*lineptr)[adjusted_size - 1] = '\0';
	return (adjusted_size - 1);
}

int main(void)
{
	char *message = NULL;
	size_t count = 0;
	ssize_t nread;
	char *token, *str;

	nread = _getline(&message, &count, stdin);
	if (nread == -1)
		return (-1);
	for (str = message; ; str = NULL)
	{
		token = strtok(str, " ");
		if (token == NULL)
			break;
		printf("Token: %s\n", token);
	}
	free(message);
	return (0);
}
