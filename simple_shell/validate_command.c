#include "main.h"

char *build_path(char *path, char *str)
{
	unsigned int i = 0;
	unsigned int len1 = strlen(path);
	unsigned int len2 = strlen(str);
	char *new_path = NULL;

	new_path = malloc(sizeof(char) * len1 + len2 + 2);
	if (new_path)
	{
		for (i = 0; i < len1; i++)
		{
			new_path[i] = path[i];
		}
		new_path[i] = '/';
		for (i = len1 + 1; i < len1 + len2 + 1; i++)
		{
			new_path[i] = str[i - len1 - 1];
		}
		new_path[len1 + len2 + 1] = '\0';
	}
	return (new_path);
}

char *validate_command(char *str, char **env)
{
	int j = 0;
	struct stat st;
	char *paths;
	char **paths_v;
	char *new_path;
	int path_fd;
	int fstat_status;
	int err;


	if (str[0] == '/')
	{
		fstat_status = stat(str, &st);
		err = errno;
		if (stat(str, &st) == 0)
		{
			return (strdup(str));
		}
		else
		{
			return (NULL);
		}
	}
	else
	{
		paths = _getenv("PATH", env);
		paths_v = _strtok(paths, ":");
		while(paths_v[j] != NULL)
		{
			path_fd = open(paths_v[j], 16384);
			if (path_fd != -1)
			{
				fstat_status = fstatat(path_fd, str, &st, 0);
				if (fstat_status == 0)
				{
					close(path_fd);
					new_path = build_path(paths_v[j], str);
					return (new_path);
				}
				else
				{
					close(path_fd);
					j++;
					continue;
				}
			}
			j++;
		}
	}
	return (NULL);
}
