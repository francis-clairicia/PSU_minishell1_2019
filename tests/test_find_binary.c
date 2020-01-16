/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_find_binary.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(find_binary_in_path, find_out_a_binary_in_path_environment)
{
    char *path = find_binary_in_path("ls", __environ);

    cr_assert_not_null(path);
    cr_expect_str_eq(path, "/usr/bin/ls");
    free(path);
}

Test(find_binary_in_path, print_error_when_not_found)
{
    char *path = NULL;

    cr_redirect_stderr();
    path = find_binary_in_path("unknown_bin", __environ);
    cr_expect_null(path);
    cr_expect_stderr_eq_str("unknown_bin: Command not found.\n");
}

Test(find_binary_in_path, handle_null_binary)
{
    char *path = NULL;

    cr_redirect_stderr();
    path = find_binary_in_path(NULL, __environ);
    cr_expect_null(path);
    cr_expect_stderr_eq_str("NULL: Command not found.\n");
}

Test(find_binary_in_path, print_error_if_path_is_not_set)
{
    char *path = NULL;
    char *envp[] = {NULL};

    cr_redirect_stderr();
    path = find_binary_in_path("ls", envp);
    cr_expect_null(path);
    cr_expect_stderr_eq_str("ls: Command not found.\n");
}