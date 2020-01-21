/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** exit.c
*/

#include "minishell.h"

int exit_builtin_command(char * const *av, char ***envp)
{
    int ac = my_array_len(av);

    my_putstr("exit\n");
    if (ac > 1)
        return (1);
    if (envp == NULL || *envp == NULL)
        return (1);
    return (1);
}