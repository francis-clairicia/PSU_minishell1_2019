/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_create_variable.c
*/

#include <criterion/criterion.h>
#include "minishell.h"

Test(create_variable, create_a_new_variable_for_the_env)
{
    char result[] = "USER 2";
    char *variable = create_variable("USER", "2");

    result[4] = 61;
    cr_expect_str_eq(variable, result);
    free(variable);
}

Test(create_variable, cant_create_if_var_is_null)
{
    char *variable = create_variable(NULL, "Hello");

    cr_expect_null(variable);
}