#include "main.h"
void _cd(char **args)
{
    if (args[1] == NULL)
    {
        const char *home_dir = getenv("HOME");
        if (home_dir != NULL)
        {
            if (chdir(home_dir) != 0)
            {
                perror("cd");
            }
        }
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("cd");
        }
    }
}