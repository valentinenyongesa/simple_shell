#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * function_path- function that returns the path of provided path
 * @path: path provided by the user
 * Return: NULL on failure and path on success
 *
 */
char *function_path(char *path)
{
	int i = 0;

	while (path[i] == ' ')
		i++;
	if (path[i] == '/' || (path[i] == '.' && path[i + 1] == '/'))
	{
		return (path);
	}
	return (NULL);
}

/**
 * free_tokens- frees memory allocated to tokens
 * @tokens: the tokens array to be freed
*/
void free_tokens(char **tokens)
{
	int i;
	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
		free(tokens[i]);
	
	free(tokens);
}

/**
* shell_prompt- A simple shell prompt
* @env: the environmental variables
* Return: 0 on success
*/
int shell_prompt(char **env)
{
	char *line = NULL, *exec_path;
	size_t len = 0;
	ssize_t nread;
	char **tokens, **envp = env;
	pid_t pid;

	/*write(STDOUT_FILENO, "$ ", 2);*/
	fflush(stdout);
	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';
		tokens = tokenize(line, ' ');
		if (_strcmp(tokens[0], "cd") == 0)/*token start */
		{
			if (tokens[1] != NULL)
			{
				if (chdir(tokens[1]) != 0)
					perror("cd");
			}
			free_tokens(tokens);
			continue;
		} else if (_strcmp(tokens[0], "exit") == 0)/*handling the exit builtin*/
		{
			free(line);
			free_tokens(tokens);
			return (0);
		}
		else if (_strcmp(tokens[0], "env") == 0)
		{
			_env(envp);
			free_tokens(tokens);
			continue;
		}
		exec_path = find_executable_path(tokens[0], envp);
		exec_path = exec_path == NULL ? function_path(tokens[0]) : exec_path;
		if (exec_path != NULL)
		{
			pid = fork();
			if (pid == -1)
				perror("fork");
			else if (pid == 0)
			{
				tokens[0] = exec_path;/*TRYING OUT SMTHG*/
				execve(exec_path, tokens, envp);
				perror("execve");
				exit(EXIT_FAILURE);
			} else
				wait(NULL);/**waiting for child process to complete*/
			free(exec_path);
		} else
			printf("command '%s' not found\n", tokens[0]);
		free(tokens);
		/*write(STDOUT_FILENO, "$ ", 2);*/
		fflush(stdout);
	}
	free(line);
	return (0);
}
/**
 * main- shell entry point
 * @ac: argument counter
 * @av: argument variables
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	(void)av;
	(void)ac;
	shell_prompt(env);
	return (0);
}
