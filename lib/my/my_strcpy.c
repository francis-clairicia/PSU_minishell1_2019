/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** Copy a string into an another
*/

#include <my.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    char new_dest[my_strlen(src)];

    if (dest == NULL)
        dest = new_dest;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = '\0';
    return (dest);
}
