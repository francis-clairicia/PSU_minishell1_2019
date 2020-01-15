/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** setenv_builtin_command.c
*/

#include "minishell.h"

static int valid_arguments(char const *variable)
{
    char alphanum[] = "Variable name must contain alphanumeric characters";
    char non_letter[] = "Variable name must begin with a letter";
    char letter = 0;

    if (!my_str_isalphanum(variable)) {
        print_error("setenv", alphanum);
        return (0);
    }
    letter = variable[0];
    if ((letter >= 'A' && letter <= 'Z') == 0
    && (letter >= 'a' && letter <= 'z') == 0) {
        print_error("setenv", non_letter);
        return (0);
    }
    return (1);
}

static void add_variable(char ***envp, char const *variable, char const *value)
{
    int i = 0;
    char **new_envp = malloc(sizeof(char *) * (my_array_len(*envp) + 2));

    if (new_envp == NULL)
        return;
    while ((*envp)[i] != NULL) {
        new_envp[i] = (*envp)[i];
        i += 1;
    }
    new_envp[i] = create_variable(variable, value);
    new_envp[i + 1] = NULL;
    free(*envp);
    *envp = new_envp;
}

static void modify_variable(char **envp, int var_index, char const *variable,
    char const *value)
{
    free(envp[var_index]);
    envp[var_index] = create_variable(variable, value);
}

void setenv_builtin_command(int ac, char **av, char ***envp)
{
    int var_index = 0;

    if (ac < 2)
        return env_builtin_command(1, (char *[]){"env"}, envp);
    else if (ac > 3)
        return print_error("setenv", "Too many arguments");
    if (!valid_arguments(av[1]))
        return;
    var_index = find_var_env(*envp, av[1]);
    if (var_index < 0)
        add_variable(envp, av[1], av[2]);
    else
        modify_variable(*envp, var_index, av[1], av[2]);
}