/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** find_quote.c
*/

#include "minishell.h"

int find_quote(char * const *command, char *quote)
{
    int i = 0;

    while (command[i] != NULL) {
        *quote = '\'';
        if (my_find_char(command[i], *quote) >= 0)
            return (i);
        *quote = '"';
        if (my_find_char(command[i], *quote) >= 0)
            return (i);
        i += 1;
    }
    return (-1);
}