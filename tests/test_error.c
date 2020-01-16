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