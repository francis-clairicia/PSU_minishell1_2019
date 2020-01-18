/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_setenv_builtin.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(setenv_builtin_command, add_var_to_environment_and_can_modify_it)
{
    char **envp = NULL;

    minishell("setenv USER user", &envp);
    minishell("setenv HOSTNAME localhost", &envp);
    minishell("setenv VAR", &envp);
    cr_assert_not_null(envp);
    cr_expect_str_eq(envp[0], "USER=user");
    cr_expect_str_eq(envp[1], "HOSTNAME=localhost");
    cr_expect_str_eq(envp[2], "VAR=");
    minishell("setenv USER name", &envp);
    cr_expect_str_eq(envp[0], "USER=name");
    my_free_word_array(envp);
}

Test(setenv_builtin_command, print_error_if_not_start_with_letter)
{
    char **envp = NULL;
    char err[] = "setenv: Variable name must begin with a letter.\n";

    cr_redirect_stderr();
    minishell("setenv 2VAR user", &envp);
    cr_expect_stderr_eq_str(err);
}

Test(setenv_builtin_command, print_error_if_var_is_non_alphanumeric_string)
{
    char **envp = NULL;
    char err[] = "setenv: "
        "Variable name must contain alphanumeric characters.\n";

    cr_redirect_stderr();
    minishell("setenv VAR5:2 user", &envp);
    cr_expect_stderr_eq_str(err);
}

Test(setenv_builtin_command, print_environment_when_no_args_is_given)
{
    char **envp = NULL;

    cr_redirect_stdout();
    minishell("setenv YO 2", &envp);
    minishell("setenv", &envp);
    cr_expect_stdout_eq_str("YO=2\n");
    my_free_word_array(envp);
}

Test(setenv_builtin_command, print_error_when_too_many_args_are_given)
{
    char **envp = NULL;
    char err[] = "setenv: Too many arguments.\n";

    cr_redirect_stderr();
    minishell("setenv VAR value1 value2", &envp);
    cr_expect_stderr_eq_str(err);
}