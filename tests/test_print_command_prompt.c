/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_print_command_prompt.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(print_command_prompt, print_user_and_cwd)
{
    char **envp = malloc(sizeof(char *));
    char *user_env[] = {"setenv", "USER", "user", NULL};
    char *host_env[] = {"setenv", "HOSTNAME", "localhost.localdomain", NULL};

    cr_redirect_stdout();
    cr_assert_not_null(envp);
    envp[0] = NULL;
    setenv_builtin_command(3, user_env, &envp);
    setenv_builtin_command(3, host_env, &envp);
    print_command_prompt("/usr/bin", envp);
    cr_expect_stdout_eq_str("[user@localhost /usr/bin]$ ");
    my_free_word_array(envp);
}

Test(print_command_prompt, print_tilde_for_the_home_path)
{
    char **envp = malloc(sizeof(char *));
    char *user_env[] = {"setenv", "USER", "user", NULL};
    char *host_env[] = {"setenv", "HOSTNAME", "localhost", NULL};
    char *home_env[] = {"setenv", "HOME", "/home/user", NULL};

    cr_redirect_stdout();
    cr_assert_not_null(envp);
    envp[0] = NULL;
    setenv_builtin_command(3, user_env, &envp);
    setenv_builtin_command(3, host_env, &envp);
    setenv_builtin_command(3, home_env, &envp);
    print_command_prompt("/home/user", envp);
    my_putchar('\n');
    print_command_prompt("/home/user/Downloads", envp);
    cr_expect_stdout_eq_str("[user@localhost ~]$ \n"
        "[user@localhost ~/Downloads]$ ");
    my_free_word_array(envp);
}

Test(print_command_prompt, handle_null_cwd_value)
{
    char **envp = malloc(sizeof(char *));
    char *user_env[] = {"setenv", "USER", "user", NULL};
    char *host_env[] = {"setenv", "HOSTNAME", "localhost.localdomain", NULL};

    cr_redirect_stdout();
    cr_assert_not_null(envp);
    envp[0] = NULL;
    setenv_builtin_command(3, user_env, &envp);
    setenv_builtin_command(3, host_env, &envp);
    print_command_prompt(NULL, envp);
    cr_expect_stdout_eq_str("[user@localhost ]$ ");
    my_free_word_array(envp);
}

Test(print_command_prompt, handle_null_env_value)
{
    cr_redirect_stdout();
    print_command_prompt("/usr/bin", NULL);
    cr_expect_stdout_eq_str("[ /usr/bin]$ ");
}