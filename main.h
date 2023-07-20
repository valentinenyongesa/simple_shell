#ifndef MAIN_H
#define MAIN_H
char **tokenize(char *string, char delim);
int shell_prompt(char **env);
char *find_exec_path(const char *exec);
char *find_executable_path(const char *exec, char **env);
#endif
