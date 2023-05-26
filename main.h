#ifndef MAIN_H
#define MAIN_H
#define EXIT_CODE 1080

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * struct inbuilt - struct to handle nbuilt commands
 * @name: name of command
 * @function: function pointer to be returned
 */
struct inbuilt
{
	char *name;
	int (*function)(char **array_of_tokens);
};


void prompt(void);
void _handle_signal(int sig);
ssize_t _getline(char **input, size_t *n, int status);
char **tokenizer(char *input, char *delim);
int _fork(char *command, char **array_of_tokens);
char *_which(char *filename);
char *char_malloc(char **str, size_t size, char *err);
char **arr_malloc(char **arr, size_t size, char *err);
void free_path(char **path_var, char **tokens);
void free_tok(char **tokens, char *input);
int arraycpy(char **dest, char **src);
int find_env(const char *name);
int _envlen(void);
void rev_string(char *s);
char *_itoa(size_t command_num);
int num_of_chars(size_t num);
int handle_errors(char **av, char **tokens, size_t num);
int is_builtin_cmd(char **tokens);
int handle_builtin(char **tokens);
int _exit_cmd(char **tokens);
int _env_cmd(char **tokens);
int _print_env(void);
char *_getenv(const char *name);
int setenv(const char *name, const char *value, int overwrite);
int unsetenv(const char *name);
#endif
