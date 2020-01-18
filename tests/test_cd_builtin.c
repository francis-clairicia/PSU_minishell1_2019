/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** test_cd_builtin.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(cd_builtin_command, change_the_current_working_directory)
{
    char save_actual_dir[4097];
    char current_dir[4097];
    char **envp = DEFAULT_ENVIRONMENT;

    cr_redirect_stderr();
    cr_assert_not_null(getcwd(save_actual_dir, 4097));
    minishell("cd /", &envp);
    cr_expect_str_eq(getcwd(current_dir, 4097), "/");
    chdir(save_actual_dir);
    minishell("cd unknown_dir", &envp);
    cr_expect_stderr_eq_str("unknown_dir: No such file or directory.\n");
}

Test(cd_builtin_command, move_to_home_path_when_no_args)
{
    char save_actual_dir[4097];
    char current_dir[4097];
    char **envp = DEFAULT_ENVIRONMENT;
    int home_index = find_var_env(envp, "HOME");
    char *home_path = get_var_value(envp, home_index);

    cr_assert_not_null(getcwd(save_actual_dir, 4097));
    minishell("cd", &envp);
    cr_expect_str_eq(getcwd(current_dir, 4097), home_path);
    chdir(save_actual_dir);
}

Test(cd_builtin_command, print_error_when_too_many_arguments_are_given)
{
    char **envp = DEFAULT_ENVIRONMENT;

    cr_redirect_stderr();
    minishell("cd / ~/Downloads", &envp);
    cr_expect_stderr_eq_str("cd: Too many arguments.\n");
}

Test(cd_builtin_command, handle_null_value)
{
    char **envp = NULL;
    char *cmd[] = {"cd", NULL};

    cr_expect_eq(cd_builtin_command(cmd, NULL), 0);
    cr_expect_eq(cd_builtin_command(cmd, &envp), 0);
}

Test(cd_builtin_command, handle_invalid_or_non_existing_home_folder)
{
    char **envp = malloc(sizeof(char *));

    cr_redirect_stderr();
    cr_assert_not_null(envp);
    envp[0] = NULL;
    cr_expect_eq(minishell("cd", &envp), 0);
    minishell("setenv HOME unknown_dir", &envp);
    minishell("cd", &envp);
    cr_expect_stderr_eq_str("unknown_dir: No such file or directory.\n");
}