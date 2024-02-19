#include <stdio.h>
#include "main.h"

int main(void)
{
	char *str;
	size_t n;
	ssize_t nread;
	int i = 0;

	nread = _getline(&str, &n, stdin);
	printf("Name is: %s\n", str);
	free(str);
	return (0);
}
