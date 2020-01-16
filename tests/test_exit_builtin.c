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
    cr_expect_eq(minishell("exit", &__environ), 1);
    cr_expect_eq(minishell("exit YO", &__environ), 1);
    cr_expect_eq(minishell("exit YO RE", &__environ), 1);
    cr_expect_eq(minishell("exit", NULL), 1);
}