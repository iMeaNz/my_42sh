/*
** EPITECH PROJECT, 2022
** my_42sh
** File description:
** main.c
*/

#include "my.h"
#include "shell.h"
#include <stdio.h>
#include <stdint.h>

void raw_parser(sh_data_t *sh);

sh_data_t init_shell(char **env)
{
    sh_data_t shell;
    shell.vars = NULL;
    uint16_t size = 0;
    for (; env[size]; ++size);
    shell.envp = malloc(sizeof(char *) * (size + 1));
    memset(shell.envp, 0, sizeof(char *) * (size + 1));
    shell.line = NULL;
    shell.old_pwd = NULL;
    shell.old_path = NULL;
    shell.last_exit_status = 0;
    shell.last_sig_status = 0;
    shell.child_pid = 0;
    shell.current_command = NULL;
    return shell;
}

int main(int argc, __attribute__((unused))char **argv, char **env)
{
    if (argc != 1) {
        dprintf(2, "42sh: Too many arguments\n");
        return 84;
    }
    sh_data_t shell = init_shell(env);
    raw_parser(&shell);
    return 0;
}