/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** find_binary_in_path.c
*/

#include "minishell.h"

static char *free_and_returns(char **word_array, char *str)
{
    my_free_word_array(word_array);
    return (str);
}

char *find_binary_in_path(char const *binary, char const *path_variable)
{
    int equal = my_find_char(path_variable, 61);
    char **path_list = my_str_to_word_array(&path_variable[equal + 1], ':');
    char *path_concat = NULL;
    int i = 0;

    if (path_list == NULL)
        return (0);
    while (path_list[i] != NULL) {
        path_concat = join_path(path_list[i], binary);
        if (path_concat != NULL && access(path_concat, F_OK) == 0)
            return (free_and_returns(path_list, path_concat));
        free(path_concat);
        i += 1;
    }
    print_error(binary, "Command not found");
    return (free_and_returns(path_list, NULL));
}