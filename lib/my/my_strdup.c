/*
** EPITECH PROJECT, 2019
** Mystrdup
** File description:
** Reproduce function
*/

#include <my.h>

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest;

    if (len < 0)
        return (NULL);
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return (NULL);
    my_strcpy(dest, src);
    return (dest);
}

char *my_strndup(char const *src, int n)
{
    int len = my_strlen(src);
    char *dest;

    if (len < 0)
        return (NULL);
    dest = malloc(sizeof(char) * (n + 1));
    if (dest == NULL)
        return (NULL);
    my_strncpy(dest, src, n);
    return (dest);
}