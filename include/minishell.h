/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell.h
*/

#ifndef HEADER_MINI_SHELL
#define HEADER_MINI_SHELL

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"

int kill(pid_t pid, int sig);

typedef void (*built_in_function_t)(int argc, char **argv, char ***envp);

enum SIGINT_HANDLER_FUNCTION
{
    PROMPT,
    PROCESS
};

struct builtin
{
    char const *command;
    built_in_function_t function;
};

int minishell(char **command, char ***envp);
void print_command_prompt(void);
char *get_path_to_executable(char const *binary, char **envp);
char *join_path(char const *path_1, char const *path_2);
char *find_binary_in_path(char const *binary, char const *path_variable);
int find_var_env(char **envp, char const *var);
int is_a_builtin_function(char **cmd, char ***envp);

void cd_builtin_command(int ac, char **av, char ***envp);
void env_builtin_command(int ac, char **av, char ***envp);
void setenv_builtin_command(int ac, char **av, char ***envp);
void unsetenv_builtin_command(int ac, char **av, char ***envp);

void bind_sigint_signal(enum SIGINT_HANDLER_FUNCTION func);
void print_error(char const *filepath, char const *error);

#endif