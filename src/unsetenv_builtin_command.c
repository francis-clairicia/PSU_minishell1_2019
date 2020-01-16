/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** unsetenv_builtin_command.c
*/

#include "minishell.h"

static void remove_var(char **envp, int var_index)
{
    int i = var_index;

    if (var_index < 0)
        return;
    free(envp[var_index]);
    while (envp[i] != NULL) {
        envp[i] = envp[i + 1];
        i += 1;
    }
}

int unsetenv_builtin_command(int ac, char **av, char ***envp)
{
    int i = 1;

    if (ac < 2) {
        print_error("unsetenv", "Too few arguments");
        return (0);
    }
    if (envp == NULL || *envp == NULL)
        return (0);
    while (i < ac) {
        remove_var(*envp, find_var_env(*envp, av[i]));
        i += 1;
    }
    return (0);
}