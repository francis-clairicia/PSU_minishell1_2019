/*
** EPITECH PROJECT, 2019
** My str len
** File description:
** Find the lenght of a string
*/

#include <my.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (-1);
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}
