#include "main.h"

int check_delim(char *str, char *delim)
{
	int i = 0;

	while (delim[i] != '\0')
	{
		if (delim[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

char *make_string(char *str, int start, int end)
{
	int len = end - start + 1;
	char *new = NULL;
	int i;

	new = malloc(sizeof(char) * len + 1);
	if (new)
	{
		for (i = start; i < end + 1; i++)
		{
			new[i - start] = str[i];
		}
		new[len] = '\0';
	}
	return (new);
}

char **_strtok(char *str, char *delim)
{
	char **tokenz = NULL;
	int i, start;
	int is_delim = 0;
	int count = 1;
	char *new;

	while (str[i] != '\0')
	{
		if (str[i] == delim[0])
			is_delim = check_delim(str + i, delim);
		if (is_delim)
		{
			if (!start)
			{
				i = i + strlen(delim);
				continue;
			}
			new = make_string(str, start, i - 1);
			tokenz = realloc(tokenz, sizeof(char *) * ++count);
			if (tokenz)
			{
				tokenz[count - 2] = new;
			}
			is_delim = 0;
		}
		i++;
	}
	tokenz[count - 1] = NULL;
	return (tokenz);
}
