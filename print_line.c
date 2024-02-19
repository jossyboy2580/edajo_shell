#include <stdio.h>

int main(void)
{
	char *lineptr = NULL;
	size_t num = 0;
	ssize_t count;

	printf("$ ");
	count = getline(&lineptr, &num, stdin);
	printf("%s", lineptr);
	return (0);
}
