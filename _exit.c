#include "main.h"

/**
 *custom_exit-implementation of the builtin exit command
 *@tokens: exit-code
 * Return: 1 if shell should exit 0 otherwise
 *
 */
int custom_exit(char **tokens)
{
	int exit_code;

	if (tokens[1] != NULL)
	{
		exit_code = atoi(tokens[1]);
		free_tokens(tokens);
		return (exit_code);
	}
	free_tokens(tokens);
	return (0);
}
