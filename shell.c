#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
int main (int ac, char **av, char **env)
{
    char *line = NULL, **tokens;
    size_t len;
    int nread;
    int interactive;

    (void)ac;
    (void)av;
    interactive = isatty(STDIN_FILENO);
    while (1)
    {
        if (interactive)
            printf("$ ");
        fflush(stdout);
        nread = getline(&line, &len, stdin);/*USER INPUT*/
        if (nread == -1)
        {
            if (interactive)
                printf("\n");
            break;
        }
        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';
        tokens = tokenize(line, ' ');/*TOKENIZING INPUT*/
        if (tokens[0] == NULL || tokens[0][0] == '#')/*EMPTY INPUT*/
        {
            free_tokens(tokens);
            continue;
        }/*HANDLING INBUILT COMMANDS*/
        if (_strcmp(tokens[0], "cd") == 0)
            _cd(tokens);
        else if (_strcmp(tokens[0], "exit") == 0)
        {    
            /*custom_exit();*/
            free_tokens(tokens);
            free(line);
            break;
        }
        else if (_strcmp(tokens[0], "env") == 0)
            _env(env);
        else 
        {/*HANDLING EXTERNAL COMMANDS*/
            exec_command(tokens, env);
        }
        free_tokens(tokens);
    }
    /*free(line);THIS LINE HAS A POTENTIAL OVERFREE*/
    return (0);
}