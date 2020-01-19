/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** cd.c
*/

#include "minishell.h"

static int go_to_default_home_path(char * const *envp)
{
    int home_index = find_var_env(envp, "HOME");
    char const *home_path = NULL;

    if (home_index < 0)
        return (0);
    home_path = envp[home_index];
    home_path = &home_path[my_find_char(home_path, 61) + 1];
    if (chdir(home_path) < 0) {
        print_error(home_path, strerror(errno));
        return (0);
    }
    return (1);
}

int cd_builtin_command(char * const *av, char ***envp)
{
    int ac = my_array_len(av);

    if (ac > 2) {
        print_error("cd", "Too many arguments");
        return (-1);
    }
    if (envp == NULL)
        return (-1);
    if (ac == 1) {
        if (!go_to_default_home_path(*envp))
            return (-1);
    } else if (chdir(av[1]) < 0) {
        print_error(av[1], strerror(errno));
        return (-1);
    }
    return (0);
}