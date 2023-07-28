#include "main.h"
#include <unistd.h>
#include <string.h>

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

int exec_command(char **tokens, char **env)
{
	pid_t pid;
    char *exec_path;
    int status = 0, is_found = 0;
    
    exec_path = find_executable_path(tokens[0], env);
    if (exec_path == NULL)
    {
        exec_path = function_path(tokens[0]);
        if (exec_path != NULL)
            is_found = 1;
    }
    if (exec_path != NULL)
    {
        pid = fork();
        if (pid == -1)
            perror("fork");
        else if (pid == 0)
        {
            if (execve(exec_path, tokens, env) == -1)
            {
                perror("execve");
                free(exec_path);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
            if (is_found == 0)
                free(exec_path);
            return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
        }
        /*free(exec_path);*/
    }
    else
    {
        printf("Command '%s' not found\n", tokens[0]);
        return (0);
    }
    /*ADDED FOR FREE*/free_tokens(tokens);
    return (-1);
}
