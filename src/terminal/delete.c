/*
** EPITECH PROJECT, 2022
** my_42sh
** File description:
** delete.c
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

int get_pos(int *y, int *x);

void backspace(int *offset, char **cmd)
{
    if (!(*cmd))
        return;
    int len = strlen(*cmd);
    int col = 0;
    int row = 0;
    delete_char_at_index(*cmd, len + *offset - 1);
    while (get_pos(&col, &row));
    dprintf(1, "\033[2K\r");
    write(0, *cmd, strlen(*cmd));
    dprintf(1, "\033[%d;%dH", row, col - 1);
}

void suppr(int *offset, char **cmd)
{
    if (*offset == 0)
        return;
    int len = (*cmd != NULL) ? strlen(*cmd) : 0;
    int row = 0;
    int col = 0;
    delete_char_at_index(*cmd, len + *offset);
    while (get_pos(&col, &row));
    dprintf(1, "\033[2K\r");
    write(0, *cmd, strlen(*cmd));
    dprintf(1, "\033[%d;%dH", row, col);
    *offset = *offset + 1;
}