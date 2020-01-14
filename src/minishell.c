/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell.c
*/

#include "minishell.h"

static int launch_process(char const *binary, char **argv, char **envp)
{
    int wstatus = 0;
    int child_pid = fork();

    if (child_pid == 0) {
        execve(binary, argv, envp);
        return (1);
    }
    waitpid(child_pid, &wstatus, 0);
    if (WIFSIGNALED(wstatus))
        my_putchar('\n');
    return (0);
}

int minishell(char **command, char ***envp)
{
    char *path_to_executable = NULL;
    int status = 0;

    if (command == NULL)
        return (1);
    if (my_strcmp(command[0], "exit") == 0)
        return (1);
    if (is_a_builtin_function(command, envp))
        return (0);
    path_to_executable = get_path_to_executable(command[0], *envp);
    if (path_to_executable == NULL)
        return (0);
    bind_sigint_signal(PROCESS);
    status = launch_process(path_to_executable, command, *envp);
    free(path_to_executable);
    return (status);
}