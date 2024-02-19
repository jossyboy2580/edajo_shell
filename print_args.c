#include <stdio.h>

int main(int ac, char **av)
{
	int i;

	i = 1;
	while (av[i] != NULL)
	{
		printf("Argument %d is %s\n", i, av[i]);
		i++;
	}
	return (0);
}
