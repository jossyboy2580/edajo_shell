#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * make_string - A function that dynamically makes a string
 * @str: A string
 * @start: The position of the first char
 * @end: The position of the last char
 * Return: The new malloced string
 */

char *make_string(char *str, int start, int end)
{
	char *new_str = NULL;
	int len = end - start + 1;
	int i;

	new_str = malloc(sizeof(char) * len + 1);
	if (new_str)
	{
		for (i = 0; i < len; i++)
		{
			new_str[i] = str[i + start];
		}
	}
	new_str[i - 1] = '\0';
	return (new_str);
}

/**
 * enlarge_toks_v - while making new strings from the _strtok func
 * This function increases the amount of space needed to accomodate
 * all
 *
 * @toks_v: An address of the toks_v array
 * @size: The new size of the array
 * Return: A pointer to the new adjusted memory location
 */

char **enlarge_toks_v(char ***toks_v, size_t size)
{
	char **toks_v_2;

	toks_v_2 = realloc(*toks_v, sizeof(char *) * size);
	if (toks_v_2 == NULL)
	{
		free(*toks_v);
		return (NULL);
	}
	*toks_v = toks_v_2;
	return (*toks_v);
}

/**
 * is_delim - This function checks if the characters in a paticular position
 * is a defined delimiter
 *
 * @str: The original string we're parsing
 * @delim: A delimiter
 * @start_pos: The position to start checking the original string if delim
 * is a delimiter
 * Return: Either 1 or 0 for if the chars is a delimiter or not
 */

int is_delim(char *str, char *delim, int start_pos)
{
	unsigned int len_delim = strlen(delim);
	unsigned int i = 0;

	for (i = 0; i < len_delim; i++)
		if (str[start_pos + i] != delim[i])
			return (0);
	return (1);
}

/**
 * _strtok - A tokenizer function that splits a string along a delimiter
 * creating an array of strings in the process
 *
 * @str: The string we want to split up
 * @delim: The delimiter along which the string will be split
 * Return: An array of strings
 */

char **_strtok(char *str, char *delim)
{
	int i;
	int start = 0;
	int started = 0;
	char **toks_v = NULL;
	char *new_token;
	size_t toks_count = 1;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_delim(str, delim, i + 1) || str[i + 1] == '\0')
		{
			if (started)
			{
				new_token = make_string(str, start, i + 1);
				toks_v = enlarge_toks_v(&toks_v, ++toks_count);
				if (toks_v != NULL)
				{
					toks_v[toks_count - 2] = new_token;
				}
				start = 0;
				started = 0;
			}
			else
			{
				i++;
				continue;
			}
		}
		else if (!is_delim(str, delim, i))
		{
			if (!started)
			{
				start = i;
				started = 1;
			}
			else
			{
				i++;
				continue;
			}
		}
		i++;
	}
	toks_v[toks_count - 1] = NULL;
	return (toks_v);
}

/**
 * free_vec - A function that takes in an array of strings and frees them
 *
 * @vec: The array of strings to be freed
 */

void free_vec(char **vec)
{
	int i = 0;

	while (vec[i] != NULL)
		free(vec[i++]);
	free(vec);
	return;
}