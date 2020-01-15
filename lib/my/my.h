/*
** EPITECH PROJECT, 2019
** Header for libmy.a
** File description:
** Contains the prototypes of all functions in libmy.a
*/

#ifndef HEADER_MY_H
#define HEADER_MY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(long nb);
int my_putnbr_base(int nbr, char const *base);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_putstr_error(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_getnbr_base(char const *str, char const *base);
void my_sort_int_array(int *array, int size);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char **my_str_to_word_array(char const *str, char separator);
void my_free_word_array(char **array);
int my_array_len(char * const *array);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_str_isalphanum(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int n);
char *my_strdup_char(char c);
char *my_nbr_to_str(int nb);
int my_nbr_len(long nb);
int my_find_char(char const *str, char c);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);
char *open_file(char const *filepath, int (*error)(char const *));
int get_next_line(char **line, int fd);

int char_is_alphanum(char c);
int index_of_first_digit(char const *str);
int index_of_first_digit_base(char const *str, char const *base);
int negative_nb(char const *str, int index_first);
void increase_address(char *address);
void print_hexa(char const *str, int min, int size);
void print_string(char const *str, int min, int size);
void convert_to_hexa(char c, char *str);
void print_non_printable_char(char c);
int test_array_int(int *array, int size);
void sort_array_int(int *array, int size);
void str_to_compare(char const *str, char *str_cmp, int i, int len_to_find);
char *convert_to_base(int nbr, char const *base);

#endif
