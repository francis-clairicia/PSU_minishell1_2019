/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_copy_env.c
*/

#include <criterion/criterion.h>
#include "minishell.h"

Test(copy_environment, create_a_new_allocated_environment_array)
{
    char **envp = DEFAULT_ENVIRONMENT;
    char **copy = copy_environment(envp);
    int i = 0;

    cr_assert_not_null(copy);
    cr_expect_eq(my_array_len(envp), my_array_len(copy));
    while (envp[i] != NULL) {
        cr_expect_str_eq(envp[i], copy[i]);
        i += 1;
    }
    my_free_word_array(copy);
}

Test(copy_environment, handle_null_value)
{
    cr_assert_null(copy_environment(NULL));
}