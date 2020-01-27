/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_error.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(print_error, print_in_stderr)
{
    cr_redirect_stderr();
    print_error("p", "n");
    cr_expect_stderr_eq_str("p: n.\n");
}

Test(print_signal, print_caught_signal)
{
    cr_redirect_stderr();
    print_signal(SIGSEGV, 1);
    print_signal(SIGFPE, 0);
    cr_expect_stderr_eq_str(
        "Segmentation fault (core dumped)\n"
        "Floating exception\n"
    );
}

Test(error_exec, returns_the_correct_strerror)
{
    cr_assert_str_eq(error_exec(ENOENT), "No such file or directory");
    cr_assert_str_eq(error_exec(ENOEXEC), "Exec format error. Wrong Architecture");
}