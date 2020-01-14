/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_builtin_command.c
*/

#include "minishell.h"

void env_builtin_command(int ac, char **av, char ***envp)
{
    int i = 0;

    if (ac > 1 && av[1] == NULL) {
        print_error("env", "Too many arguments");
        return;
    }
    if (*envp == NULL)
        return;
    while ((*envp)[i] != NULL) {
        my_putstr((*envp)[i]);
        my_putchar('\n');
        i += 1;
    }
}