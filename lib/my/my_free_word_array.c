/*
** EPITECH PROJECT, 2019
** My_Lib_C
** File description:
** my_free_word_array.c
*/

#include "my.h"

void my_free_word_array(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        free(array[i]);
        i += 1;
    }
    free(array);
}