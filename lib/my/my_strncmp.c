/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** Compare the n first character of two strings
*/

#include <my.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    char s1_cut[n + 1];
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (my_strcmp(s1, s2));
    if (n >= my_strlen(s1))
        return (my_strcmp(s1, s2));
    while (i < n) {
        s1_cut[i] = s1[i];
        i += 1;
    }
    s1_cut[i] = '\0';
    return (my_strcmp(s1_cut, s2));
}
