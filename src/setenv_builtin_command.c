/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** setenv_builtin_command.c
*/

#include "minishell.h"

static int valid_arguments(char **argv)
{
    int i = 1;

    while (argv[i] != NULL) {
        if (my_find_char(argv[i], ' ') >= 0) {
            print_error(argv[i], "Spaces in argument");
            return (0);
        }
        if (my_find_char(argv[i], 61) < 0) {
            print_error(argv[i], "You must define a value");
            return (0);
        }
        i += 1;
    }
    return (1);
}

static void add_variable(char ***envp, char const *value)
{
    int i = 0;
    char **new_envp = malloc(sizeof(char *) * (my_array_len(*envp) + 2));

    if (new_envp == NULL)
        return;
    while ((*envp)[i] != NULL) {
        new_envp[i] = (*envp)[i];
        i += 1;
    }
    new_envp[i] = my_strdup(value);
    new_envp[i + 1] = NULL;
    free(*envp);
    *envp = new_envp;
}

static void modify_variable(char **envp, int var_index, char const *value)
{
    free(envp[var_index]);
    envp[var_index] = my_strdup(value);
}

void setenv_builtin_command(int ac, char **av, char ***envp)
{
    int i = 1;
    int var_index = 0;

    if (ac < 2) {
        print_error("setenv", "Not enought arguments");
        return;
    }
    if (!valid_arguments(av))
        return;
    while (i < ac) {
        var_index = find_var_env(*envp, av[i]);
        if (var_index < 0)
            add_variable(envp, av[i]);
        else
            modify_variable(*envp, var_index, av[i]);
        i += 1;
    }
}