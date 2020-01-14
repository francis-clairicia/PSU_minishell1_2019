/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** cd_builtin_command.c
*/

#include "minishell.h"

static void go_to_default_home_path(char **envp)
{
    int home_index = find_var_env(envp, "HOME");
    char const *home_path = NULL;

    if (home_index < 0)
        return;
    home_path = envp[home_index];
    home_path = &home_path[my_find_char(home_path, 61) + 1];
    if (chdir(home_path) < 0)
        print_error(home_path, strerror(errno));
}

void cd_builtin_command(int argc, char **argv, char ***envp)
{
    if (envp == NULL || *envp == NULL)
        return;
    if (argc > 2) {
        print_error("cd", "Too many arguments");
        return;
    }
    if (argc == 1) {
        go_to_default_home_path(*envp);
        return;
    }
    if (chdir(argv[1]) < 0)
        print_error(argv[1], strerror(errno));
}