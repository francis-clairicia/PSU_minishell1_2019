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
    int user_index = 0;
    int host_index = 0;
    char **envp = NULL;

    minishell("setenv USER user", &envp);
    minishell("setenv HOSTNAME localhost", &envp);
    user_index = find_var_env(envp, "USER");
    host_index = find_var_env(envp, "HOSTNAME");
    cr_expect_eq(user_index, 0);
    cr_expect_eq(host_index, 1);
    cr_expect_str_eq(get_var_value(envp, user_index), "user");
    cr_expect_str_eq(get_var_value(envp, host_index), "localhost");
    minishell("setenv USER name", &envp);
    cr_expect_str_eq(get_var_value(envp, user_index), "name");
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
    char result[] = "YO 2\n";
    char **envp = NULL;

    result[2] = 61;
    cr_redirect_stdout();
    minishell("setenv YO 2", &envp);
    minishell("setenv", &envp);
    cr_expect_stdout_eq_str(result);
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