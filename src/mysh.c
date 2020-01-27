/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** mysh.c
*/

#include "minishell.h"

static int command_prompt(char **line, int stop_shell)
{
    char current_directory[4097];

    if (stop_shell < 0)
        stop_shell = 0;
    else if (stop_shell) {
        free(*line);
        return (0);
    }
    bind_sigint_signal(PROMPT);
    print_command_prompt(getcwd(current_directory, 4097), DEFAULT_ENVIRONMENT);
    if (!get_next_line(line, 0))
        *line = my_strdup("exit");
    if (my_strlen(*line) == 0)
        return (command_prompt(line, -1));
    return (1);
}

int mysh(void)
{
    char *cmd = NULL;
    char **envp = my_array_cpy(DEFAULT_ENVIRONMENT);
    int stop_shell = 0;

    if (envp == NULL)
        return (84);
    while (command_prompt(&cmd, stop_shell)) {
        stop_shell = minishell(cmd, &envp);
        if (envp == NULL)
            stop_shell = 1;
    }
    my_free_word_array(envp);
    return (0);
}