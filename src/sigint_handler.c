/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** sigint_handler.c
*/

#include "minishell.h"

void sigint_handler_for_prompt(int signum)
{
    my_putstr("\n");
    print_command_prompt();
}

void sigint_handler_for_process(int signum)
{
    signum = SIGCHLD;
    kill(getpid(), signum);
}

void bind_sigint_signal(enum SIGINT_HANDLER_FUNCTION func)
{
    void (*sigint_handler[])(int signum) = {
        sigint_handler_for_prompt,
        sigint_handler_for_process
    };

    signal(SIGINT, sigint_handler[func]);
}