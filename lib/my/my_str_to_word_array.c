/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Split a string in a word array
*/

#include <stdlib.h>
#include "my.h"

int get_nb_words(char const *str, char separator)
{
    int nb = 1;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != separator) {
            i += 1;
            continue;
        }
        nb += 1;
        while (str[i] != '\0' && str[i] == separator)
            i += 1;
    }
    return (nb);
}

int get_index_end_word(char const *str, char separator)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != separator)
            i += 1;
        else
            break;
    }
    return (i);
}

void generate_array(char **array, char const *str,
    int nb_words, char separator)
{
    int i = 0;
    int index_word;

    while (i < nb_words) {
        index_word = get_index_end_word(str, separator);
        array[i] = my_strndup(str, index_word);
        while (str[index_word] != '\0' && str[index_word] == separator)
            index_word += 1;
        str = &str[index_word];
        i += 1;
    }
}

char const *skip_first_separators(char const *str, char separator)
{
    int n = 0;

    while ((n = my_find_char(str, separator)) == 0)
        str = &str[n + 1];
    return (str);
}

char **my_str_to_word_array(char const *str, char separator)
{
    int nb_words;
    char **array;

    if (str == NULL)
        return (NULL);
    str = skip_first_separators(str, separator);
    if (my_strlen(str) == 0)
        return (NULL);
    nb_words = get_nb_words(str, separator);
    array = malloc(sizeof(char *) * (nb_words + 1));
    if (array == NULL)
        return (NULL);
    generate_array(array, str, nb_words, separator);
    array[nb_words] = NULL;
    return (array);
}
