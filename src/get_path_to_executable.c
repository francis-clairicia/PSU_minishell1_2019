/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** get_path_to_executable.c
*/

#include "minishell.h"

static int check_access(char const *filepath)
{
    if (filepath == NULL)
        return (0);
    if (access(filepath, F_OK) < 0) {
        print_error(filepath, "Command not found");
        return (0);
    } else if (access(filepath, X_OK) < 0){
        print_error(filepath, strerror(errno));
        return (0);
    }
    return (1);
}

char *get_path_to_executable(char const *binary, char **envp)
{
    int path_index = find_var_env(envp, "PATH");
    char *filepath = NULL;

    if (my_find_char(binary, '/') >= 0) {
        if (!check_access(binary))
            return (NULL);
        return (my_strdup(binary));
    }
    if (path_index < 0)
        return (NULL);
    filepath = find_binary_in_path(binary, envp[path_index]);
    if (!check_access(filepath)) {
        free(filepath);
        return (NULL);
    }
    return (filepath);
}