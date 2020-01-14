/*
** EPITECH PROJECT, 2019
** Find prime sup
** File description:
** Find the smallest prime number greather than or equal to the number n
*/

#include <my.h>

int my_find_prime_sup(int nb)
{
    if (nb <= 1)
        return (2);
    while (my_is_prime(nb) == 0)
        nb += 1;
    return (nb);
}
