/*
** EPITECH PROJECT, 2019
** my_strstr.c
** File description:
** Find a string into an another
*/

#include <my.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int len_str_to_find = my_strlen(to_find);
    char str_cmp[len_str_to_find + 1];

    if (str == NULL || to_find == NULL || my_strlen(str) < len_str_to_find)
        return (NULL);
    while (str[i + len_str_to_find] != '\0') {
        my_strncpy(str_cmp, &str[i], len_str_to_find);
        if (my_strcmp(str_cmp, to_find) == 0)
            return (&str[i]);
        i += 1;
    }
    return (NULL);
}
