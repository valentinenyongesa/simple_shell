#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * tokenize- returns tokens from a string input
 * @string: an input string to be tokenized
 * Return: an array of tokens
*/
char **tokenize(char *string)
{
	size_t i = 0, j = 0;
	char *temp = malloc(sizeof(char *) * (strlen(string) + 1));
	char **tokens = malloc(sizeof(char **) * 100);
	int token_pos = 0;

	while (string[i] != '\0')
	{
		while (string[i] == ' ')
		{
			i++;
		}

		while (string[i] != ' ' && string[i] != '\0')
		{
			temp[j] = string[i];
			i++;
			j++;
		}
		temp[j] = '\0';
		if (j > 0)
		{
			tokens[token_pos] = temp;
			token_pos++;
			temp  = malloc(sizeof(char *) * (strlen(string) + 1));
			j = 0;
		}
	}

	tokens[token_pos] = NULL;
	return (tokens);
}

