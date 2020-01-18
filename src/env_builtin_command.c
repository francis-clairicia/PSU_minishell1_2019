/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_builtin_command.c
*/

#include "minishell.h"

int env_builtin_command(char **av, char ***envp)
{
    int ac = my_array_len(av);
    int i = 0;

    if (ac > 1) {
        print_error("env", "Too many arguments");
        return (0);
    }
    if (*envp == NULL)
        return (0);
    while ((*envp)[i] != NULL) {
        my_putstr((*envp)[i]);
        my_putchar('\n');
        i += 1;
    }
    return (0);
}