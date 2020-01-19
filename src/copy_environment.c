/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** copy_environment.c
*/

#include "minishell.h"

char **copy_environment(char * const *envp)
{
    int i = 0;
    char **envp_copy = NULL;

    if (envp == NULL)
        return (NULL);
    envp_copy = malloc(sizeof(char *) * (my_array_len(envp) + 1));
    if (envp_copy == NULL)
        return (NULL);
    while (envp[i] != NULL) {
        envp_copy[i] = my_strdup(envp[i]);
        if (envp_copy[i] == NULL) {
            my_free_word_array(envp_copy);
            return (NULL);
        }
        i += 1;
    }
    envp_copy[i] = NULL;
    return (envp_copy);
}