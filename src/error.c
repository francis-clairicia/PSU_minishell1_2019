/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** error.c
*/

#include "minishell.h"

void print_error(char const *filepath, char const *error)
{
    my_putstr_error(filepath);
    my_putstr_error(": ");
    my_putstr_error(error);
    my_putstr_error(".\n");
}

char *error_exec(int errnum)
{
    if (errnum == ENOEXEC)
        return ("Exec format error. Wrong architecture");
    return (strerror(errnum));
}

void print_signal(int wstatus)
{
    int signum = WTERMSIG(wstatus);

    if (signum == SIGFPE)
        my_putstr_error("Floating exception");
    else
        my_putstr_error(strsignal(signum));
    if (WCOREDUMP(wstatus))
        my_putstr_error(" (core dumped)");
    my_putstr_error("\n");
}