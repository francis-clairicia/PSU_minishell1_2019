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

static char **copy_environment(char *envp[])
{
    int i = 0;
    char **envp_copy = malloc(sizeof(char *) * (my_array_len(envp) + 1));

    if (envp_copy == NULL)
        return (NULL);
    while (envp[i] != NULL) {
        envp_copy[i] = my_strdup(envp[i]);
        if (envp_copy[i] == NULL) {
            my_free_word_array(envp_copy);
            return (NULL);
        }
        i += 1;
    }
    envp_copy[i] = NULL;
    return (envp_copy);
}

static void set_shell_env(char ***envp, char const *binary_name)
{
    char current_dir[4097];
    char *cmd[] = {"setenv", "SHELL", "", NULL};

    if (binary_name[0] != '/')
        cmd[2] = join_path(getcwd(current_dir, 4097), &binary_name[2]);
    else
        cmd[2] = my_strdup(binary_name);
    setenv_builtin_command(3, cmd, envp);
    free(cmd[2]);
}

static int command_prompt(char **line)
{
    char current_directory[4097];

    bind_sigint_signal(PROMPT);
    print_command_prompt(getcwd(current_directory, 4097), __environ);
    if (!get_next_line(line, 0)) {
        my_putstr("exit\n");
        return (0);
    }
    if (my_strlen(*line) == 0)
        return (0);
    return (1);
}

int main(int ac, char **av, char **envp)
{
    char *cmd = NULL;
    char **new_envp = NULL;
    int stop_shell = 0;

    if (ac > 1 && my_strcmp(av[1], "-h") == 0)
        return (print_help());
    new_envp = copy_environment(envp);
    if (new_envp == NULL)
        return (84);
    set_shell_env(&new_envp, av[0]);
    while (!stop_shell && command_prompt(&cmd)) {
        stop_shell = minishell(cmd, &new_envp);
        if (new_envp == NULL)
            stop_shell = 1;
    }
    free(cmd);
    my_free_word_array(new_envp);
    return (0);
}