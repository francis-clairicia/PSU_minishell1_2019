/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_unsetenv_builtin.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(unsetenv_builtin_command, remove_var_form_environment)
{
    char **envp = NULL;

    minishell("setenv YO 2", &envp);
    minishell("setenv USER user", &envp);
    minishell("setenv DISPLAY :0.0", &envp);
    cr_expect_neq(find_var_env(envp, "YO"), -1);
    cr_expect_neq(find_var_env(envp, "USER"), -1);
    cr_expect_neq(find_var_env(envp, "DISPLAY"), -1);
    minishell("unsetenv YO USER DISPLAY", &envp);
    cr_assert_not_null(envp);
    cr_expect_null(envp[0]);
    cr_expect_eq(find_var_env(envp, "YO"), -1);
    cr_expect_eq(find_var_env(envp, "USER"), -1);
    cr_expect_eq(find_var_env(envp, "DISPLAY"), -1);
    my_free_word_array(envp);
}

Test(unsetenv_builtin_command, cant_remove_from_null_env)
{
    char **envp = NULL;

    cr_expect_eq(minishell("unsetenv VAR", NULL), 0);
    cr_expect_eq(minishell("unsetenv VAR", &envp), 0);
}

Test(unsetenv_builtin_command, print_error_when_no_arg_is_given)
{
    cr_redirect_stderr();
    cr_expect_eq(minishell("unsetenv", NULL), 0);
    cr_expect_stderr_eq_str("unsetenv: Too few arguments.\n");
}