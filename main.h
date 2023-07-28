#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
char **tokenize(char *string, char delim);
int shell_prompt(char **env);
char *find_executable_path(const char *exec, char **env);
int _strcmp(char *s1, char *s2);
size_t _strlen(const char *str);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcpy(char *dest, char *src);
void free_tokens(char **tokens);
void _env(char **env);
int custom_exit();
int exec_command(char **tokens, char **env);
char *function_path(char *path);
void _cd(char **args);
#endif
