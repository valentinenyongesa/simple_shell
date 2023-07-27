#include "main.h"

/**
 * _env-prints the current working environment
 * @env:array of environmental variables
 * Return: void
 */

void _env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
