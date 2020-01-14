/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** print_command_prompt.c
*/

#include "minishell.h"

static void print_current_directory(char const *cwd)
{
    char home_path[] = "/home/";
    int len_home_path = my_strlen(home_path);

    if (my_strncmp(cwd, home_path, len_home_path) != 0) {
        my_putstr(cwd);
        return;
    }
    my_putstr("~");
    cwd = &cwd[len_home_path];
    if (my_find_char(cwd, '/') < 0)
        return;
    cwd = &cwd[my_find_char(cwd, '/') + 1];
    if (my_strlen(cwd) == 0)
        return;
    my_putstr("/");
    my_putstr(cwd);
}

void print_command_prompt(void)
{
    char current_directory[4097];

    if (getcwd(current_directory, 4096) == NULL)
        return;
    my_putstr("[");
    print_current_directory(current_directory);
    my_putstr("]$ ");
}