#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
/**
 * find_executable_path- function finds the full path to an exeecutable bin
 * file
 * @exec: the executable to be looked for
 * @env: the environment variables
 * Return: path to the executable file
 */
char *find_executable_path(const char *exec, char **env)
{
	char *path_env = NULL, *path = NULL, *dir = NULL, *full_path = NULL;
	size_t len, i;

	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], "PATH=", 5) == 0)
		{
			path_env = env[i] + 5;
			break;
		}
	}

	if (path_env == NULL)
		return (NULL);

	path = strdup(path_env);
	dir = strtok(path, ":");
	while (dir != NULL)
	{
		len = _strlen(dir) + 1 + _strlen(exec) + 1;
		full_path = (char *)malloc(len);

		if (full_path == NULL)
		{
			perror("Memory allocation error");
			free(path);
			return (NULL);
		}
		snprintf(full_path, len, "%s/%s", dir, exec);

		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
