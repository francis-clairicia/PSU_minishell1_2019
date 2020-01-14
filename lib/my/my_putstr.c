/*
** EPITECH PROJECT, 2019
** My put str
** File description:
** Display a string
*/

#include "my.h"

static int putstr_in_fd(int fd, char const *str)
{
    if (str == NULL)
        return (putstr_in_fd(fd, "NULL"));
    return (write(1, str, my_strlen(str)) != -1);
}

int my_putstr(char const *str)
{
    return (putstr_in_fd(STDOUT_FILENO, str));
}

int my_putstr_error(char const *str)
{
    return (putstr_in_fd(STDERR_FILENO, str));
}