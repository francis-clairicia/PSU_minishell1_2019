/*
** EPITECH PROJECT, 2019
** My put nbr base
** File description:
** Base
*/

#include <my.h>
#include <mylist.h>

int my_putnbr_base(int nbr, char const *base)
{
    char *nbr_converted = convert_to_base(nbr, base);

    my_putstr(nbr_converted);
    free(nbr_converted);
    return (0);
}
