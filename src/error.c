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