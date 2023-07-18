#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>

#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - write UNIX command line interpreter
 * @argc: argument count
 * @argv: argument vector
 * @env: the environ
 *
 * Return: 0
 */

int main(int argc, char *argv[], char **env)
{
	char *buf = NULL;
	char *new = "#cisfun$ ";
	size_t buf_size = 0;
	ssize_t n;
	int i;
	bool pipe = false;
	pid_t pid;
	(void)argc;
	(void)argv;

	while (1 && !pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			pipe = true;
		write(STDOUT_FILENO, "#cisfun$ ", 9);

		n = getline(&buf, &buf_size, stdin);
		if (n == -1)
		{
			perror("Error (getline)");
			free(buf);
			exit(EXIT_FAILURE);
		}
		if (buf[n - 1] == '\n')
			buf[n - 1] = '\0';

		pid = fork();

		if (pid == -1)
		{
			perror("Error (fork)");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
			execve(buf, &new, env);
		if (waitpid(pid, &i, 0) == -1)
		{
			perror("Error (wait)");
			exit(EXIT_FAILURE);
		}
	}
	free(buf);
	return (0);
}
