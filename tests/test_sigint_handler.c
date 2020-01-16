/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_sigint_handler.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(sigint_handler_for_prompt, print_again_the_prompt_when_sigint_is_raised)
{
    char **envp = malloc(sizeof(char *));
    char *user_env[] = {"setenv", "USER", "user", NULL};
    char *hostname_env[] = {"setenv", "HOSTNAME", "localhost", NULL};

    cr_redirect_stdout();
    cr_assert_not_null(envp);
    envp[0] = NULL;
    setenv_builtin_command(3, user_env, &envp);
    setenv_builtin_command(3, hostname_env, &envp);
    bind_sigint_signal(PROMPT);
    kill(getpid(), SIGINT);
    my_free_word_array(envp);
}

Test(sigint_handler_for_process, kill_the_child_process)
{
    cr_redirect_stderr();
    sigint_handler_for_process(SIGKILL);
    cr_expect_stderr_eq_str("\n");
}