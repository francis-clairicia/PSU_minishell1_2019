/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** sigint_handler.c
*/

#include "minishell.h"

void sigint_handler_for_prompt(int signum)
{
    char current_directory[4097];

    (void)signum;
    my_putstr("\n");
    print_command_prompt(getcwd(current_directory, 4097), DEFAULT_ENVIRONMENT);
}

void sigint_handler_for_process(int signum)
{
    (void)signum;
    kill(getpid(), SIGCHLD);
    my_putstr_error("\n");
}

sighandler_t bind_sigint_signal(int func)
{
    sighandler_t sigint_handler[] = {
        sigint_handler_for_prompt,
        sigint_handler_for_process
    };

    return (signal(SIGINT, sigint_handler[func]));
}