#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _getline - A function to recieve input from the user
 *
 * @lineptr: The buffer to which we will save the entered chars
 * @n: The initial size of lineptr (malloced)
 * @stream: The stream we will get the input from
 * Return: The actual count of the number of chars entered
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t adjusted_size = 1;
	char buff;
	ssize_t status;
	(void)n;
	int streamno = fileno(stream);

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
