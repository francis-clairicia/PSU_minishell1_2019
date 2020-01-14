/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** builtin_functions.c
*/

#include "minishell.h"

static const struct builtin builtin_functions_list[] = {
    {"cd", cd_builtin_command},
    {"env", env_builtin_command},
    {"setenv", setenv_builtin_command},
    {"unsetenv", unsetenv_builtin_command},
    {NULL, NULL}
};

int is_a_builtin_function(char **cmd, char ***envp)
{
    int i = 0;
    char const *command = NULL;
    built_in_function_t function = NULL;

    while (builtin_functions_list[i].command != NULL) {
        command = builtin_functions_list[i].command;
        function = builtin_functions_list[i].function;
        if (my_strcmp(cmd[0], command) == 0) {
            function(my_array_len(cmd), cmd, envp);
            return (1);
        }
        i += 1;
    }
    return (0);
}