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

typedef void (*builtin_function_t)(int argc, char **argv, char ***envp);
typedef __sighandler_t sighandler_t;

enum SIGINT_HANDLER_FUNCTION
{
    PROMPT,
    PROCESS
};

struct builtin
{
    char const *command;
    builtin_function_t function;
};

int minishell(char **command, char ***envp);
char *get_path_to_executable(char const *binary, char **envp);
char *join_path(char const *path_1, char const *path_2);
char *find_binary_in_path(char const *binary, char **envp);
int find_var_env(char **envp, char const *var);
char *get_var_value(char **envp, int index);
char *create_variable(char const *variable, char const *value);
builtin_function_t is_builtin(char **cmd);

void cd_builtin_command(int ac, char **av, char ***envp);
void env_builtin_command(int ac, char **av, char ***envp);
void setenv_builtin_command(int ac, char **av, char ***envp);
void unsetenv_builtin_command(int ac, char **av, char ***envp);

void print_command_prompt(char const *cwd, char **envp);
void print_current_directory(char const *cwd, char **envp);
void print_user(char **envp);

sighandler_t bind_sigint_signal(enum SIGINT_HANDLER_FUNCTION func);
void print_error(char const *filepath, char const *error);

#endif