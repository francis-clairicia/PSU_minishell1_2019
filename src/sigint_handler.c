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

    if (signum != SIGINT)
        return;
    my_putstr("\n");
    print_command_prompt(getcwd(current_directory, 4097), __environ);
}

void sigint_handler_for_process(int signum)
{
    if (signum == SIGINT)
        kill(getpid(), SIGCHLD);
    my_putstr_error("\n");
}

sighandler_t bind_sigint_signal(int func)
{
    void (*sigint_handler[])(int signum) = {
        sigint_handler_for_prompt,
        sigint_handler_for_process
    };

    return (signal(SIGINT, sigint_handler[func]));
}