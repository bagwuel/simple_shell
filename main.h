#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int _putchar(char c);
char *_pathcat(char *str, char *s);
char *_prompt(void);
char **_tokenizer(char *str);
int _forkexec(char **command, char *av);
char *_command_path(char **env, char *command);
void _printenv(char **env);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, size_t size);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, const char *accept);
char *_strpbrk(char *s, const char *accept);
void f_exit(char *status);
int _atoi(char *s);
char *_strdup(char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);

#endif
