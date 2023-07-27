#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <ctype.h>

/**
 * tokenize- returns tokens of a string based on a delimiter
 * @string: string to be tokenized
 * @delim: delimiter
 * Return: tokens from the string
 */
char **tokenize(char *string, char delim)
{
	size_t i = 0, j = 0;
	char *temp = malloc(sizeof(char) * (_strlen(string) + 1));
	char **tokens = malloc(sizeof(char *) * 100);
	int token_pos = 0;

	if (temp == NULL || tokens == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	while (string[i] != '\0')
	{
		while (string[i] == delim)
		{
			i++;
		}
		temp[j] = string[i];
		while (string[i] != delim && string[i] != '\0')
		{
			temp[j++] = string[i++];
		}
		temp[j] = '\0';
		if (j > 0)
		{
			tokens[token_pos] = malloc(sizeof(char) * (_strlen(temp) + 1));
			if (tokens[token_pos] == NULL)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
			_strcpy(tokens[token_pos], temp);
			token_pos++;
			j = 0;
		}
	}
	free(temp);
	tokens[token_pos] = NULL;
	return (tokens);
}

