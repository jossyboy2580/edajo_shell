#include <stdio.h>
#include "main.h"

int main(void)
{
	char *lineptr = NULL;
	size_t num = 0;
	ssize_t count;

	printf("$ ");
	fflush(stdout);
	count = _getline(&lineptr, &num, stdin);
	if (count != -1)
		printf("%s", lineptr);
	return (0);
}
