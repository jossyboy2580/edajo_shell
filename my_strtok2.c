/**
 * TODO I intend to write a strtok function that uses static variable to keep track
 * of the pointer changes inbetween successive calls to it
 * imitating the dynamic nature of the original strtok functio*/



char *_strtok(char *str, char del)
{
	static int next_node_pos = 0;
	static char *_str = str + next_node_pos;
	int i = 0;
	int start, started = 0;
	char *new_token;

	if (str == NULL)
	{	str = _str;
		next_node_pos = ;
	}
	while (str[i] != '\0')
	{
		if (str[i] == del || str[i + 1] == '\0')
		{
			if (started)
			{
				new_token = make_string(str, start, i);
				printf("Token: %s, %lu chars long\n", new_token, strlen(new_token));
				free(new_token);
				start = 0;
				started = 0;
			}
			else
			{
				i++;
				continue;
			}
		}
		else if (str[i] != del)
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
}
