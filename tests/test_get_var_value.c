/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_get_var_value.c
*/

#include <criterion/criterion.h>
#include "minishell.h"

Test(get_var_value, get_value_of_variable_environment)
{
    char *custom_env[] = {"USER", NULL};
    int display_index = find_var_env(__environ, "DISPLAY");

    cr_expect_str_eq(get_var_value(__environ, display_index), ":0.0");
    cr_expect_null(get_var_value(__environ, -1));
    cr_expect_null(get_var_value(NULL, display_index));
    cr_expect_null(get_var_value(custom_env, 0));
}