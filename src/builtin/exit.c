/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** exit.c
*/

#include "minishell.h"

int exit_builtin_command(char * const *av, char ***envp)
{
    my_putstr("exit\n");
    (void)av;
    (void)envp;
    return (1);
}