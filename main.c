#include <stdio.h>
#include "main.h"

int main(void)
{
	char *str;
	char **tokez;
	size_t n;
	ssize_t nread;
	int i = 0;

	nread = _getline(&str, &n, stdin);
	tokez = _strtok(str, " ");
	while (tokez[i] != NULL)
	{
		printf("Token: %s", tokez[i]);
		i++;
	}
	i = 0;
	while (tokez[i] != NULL)
		free(tokez[i++]);
	free(tokez);
	return (0);
}
