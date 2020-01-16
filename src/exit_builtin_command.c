/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** exit_builtin_command.c
*/

#include "minishell.h"

int exit_builtin_command(int ac, char **av, char ***envp)
{
    if (ac > 1 && av[2] == NULL)
        return (1);
    if (envp == NULL || *envp == NULL)
        return (1);
    return (1);
}