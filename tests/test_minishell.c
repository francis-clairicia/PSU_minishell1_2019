/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_minishell.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(minishell, launch_command_like_an_another_shell)
{
    int status = 0;

    cr_redirect_stdout();
    status = minishell("ls main.c", &__environ);
    if (status == 1) {
        cr_expect_eq(kill(getpid(), SIGCHLD), 0);
    } else {
        cr_expect_eq(status, 0);
        cr_expect_stdout_eq_str("main.c\n");
    }
}

Test(minishell, handle_null_command)
{
    cr_assert_eq(minishell(NULL, &__environ), 1);
}