/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** Display a character
*/

#include "my.h"

int my_putchar(char c)
{
    return (write(1, &c, 1) != -1);
}
