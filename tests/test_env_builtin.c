/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_env_builtin.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(env_builtin_command, print_environment)
{
    char result[] = "YO 2\n";
    char **envp = NULL;

    result[2] = 61;
    cr_redirect_stdout();
    minishell("setenv YO 2", &envp);
    minishell("env", &envp);
    cr_expect_stdout_eq_str(result);
    my_free_word_array(envp);
}

Test(env_builtin_command, handle_args)
{
    char **envp = NULL;

    cr_redirect_stderr();
    minishell("setenv YO 2", &envp);
    minishell("env -i", &envp);
    cr_expect_stderr_eq_str("env: Too many arguments.\n");
    my_free_word_array(envp);
}

Test(env_builtin_command, handle_null_env)
{
    char **envp = NULL;

    cr_assert_eq(minishell("env", &envp), 0);
}