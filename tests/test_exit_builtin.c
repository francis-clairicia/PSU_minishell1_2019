/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_exit_builtin.c
*/

#include <criterion/criterion.h>
#include "minishell.h"

Test(exit_builtin_command, close_the_minishell)
{
    char **envp = copy_environment(DEFAULT_ENVIRONMENT);

    cr_expect_eq(minishell("exit", &envp), 1);
    cr_expect_eq(minishell("exit YO", &envp), 1);
    cr_expect_eq(minishell("exit YO RE", &envp), 1);
    cr_expect_eq(minishell("exit", NULL), 1);
    my_free_word_array(envp);
}