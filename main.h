#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
char **tokenize(char *string, char delim);
int shell_prompt(char **env);
char *find_executable_path(const char *exec, char **env);
int _strcmp(char *s1, char *s2);
size_t _strlen(const char *str);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcpy(char *dest, char *src);
#endif
