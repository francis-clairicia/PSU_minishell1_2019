/*
** EPITECH PROJECT, 2019
** my_find_char
** File description:
** Find a char into a string
*/

#include <my.h>

int my_find_char(char const *str, char c)
{
    int i = 0;

    if (str == NULL)
        return (-1);
    while (str[i] != '\0') {
        if (str[i] == c)
            return (i);
        i += 1;
    }
    return (-1);
}
