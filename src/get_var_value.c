/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** get_var_value.c
*/

#include "minishell.h"

char *get_var_value(char **envp, int index)
{
    int equal_index = 0;

    if (envp == NULL)
        return (NULL);
    if (index < 0 || index >= my_array_len(envp))
        return (NULL);
    equal_index = my_find_char(envp[index], 61);
    if (equal_index < 0)
        return (NULL);
    return (&(envp[index][equal_index + 1]));
}