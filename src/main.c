/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main.c
*/

#include "minishell.h"

static int print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./mysh\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tA C-coded minishell\n");
    return (0);
}

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

int main(int ac, char **av)
{
    char *cmd = NULL;
    char **envp = NULL;
    int stop_shell = 0;
    int output = 0;

    if (ac > 1 && my_strcmp(av[1], "-h") == 0)
        return (print_help());
    envp = copy_environment(DEFAULT_ENVIRONMENT);
    if (envp == NULL)
        return (84);
    while (command_prompt(&cmd, stop_shell)) {
        stop_shell = minishell(cmd, &envp);
        if (envp == NULL)
            stop_shell = 1;
        if (stop_shell < 0)
            output = 84;
    }
    my_free_word_array(envp);
    return (output);
}