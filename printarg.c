#include <stdio.h>

/**
 * main - Prints all arguments , without using ac
 * @ac: Argument count
 * @argv: Argument vectors
 * Return: Always 0 on Success
 */
int main(int ac, char **argv)
{
	char **ar = argv;

	while (*ar != NULL)
	{
		printf("%s\n", *ar);
		ar++;
	}
	return (0);
}
