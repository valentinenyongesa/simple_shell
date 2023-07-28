#include "main.h"
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
	{
		free(tokens[i]);
		tokens[i] = NULL;
	}
	free(tokens);
}