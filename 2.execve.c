#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * main - executing a program with execve
 *
 * Return: 0
 */

int main(void)
{
	char cmd[] = "/bin/ls";
	char *argv[] = {"ls", "-l", NULL};
	char *env[] = {NULL};

	if (execve(cmd, argv, env) == -1)
	{
		perror("Error");
	}
	return (0);
}
