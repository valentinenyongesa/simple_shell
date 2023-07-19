#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * main - write UNIX command line interpreter
 *
 * Return: 0
 */

int main(void)
{
	char *buf = NULL;
	char *new = "#cisfun$ ";
	size_t buf_size = 0;
	pid_t pid;
	ssize_t read;
	int s;
	int i = 0;
	char cmd[] = "/bin/ls";
	char *arg[] = {"ls", NULL};
	char *env[] = {NULL};

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		read = getline(&buf, &buf_size, stdin);
		if (read != -1 && buf[read - 1] == '\n')
			buf[read - 1] = '\0';
		char *token = strtok(buf, " ");
		char *args[BUFFER_SIZE];
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		if (strcmp(args[0], "exit") == 0)
			break;
		pid = fork();
		if (pid == 0)
		{
			if (execve(cmd, arg, env) < 0)
			{
				perror("error execve");
			}
		}
		else
		{
			while (wait(&s) != pid)
				;
		}

	}
	free(buf);
}
