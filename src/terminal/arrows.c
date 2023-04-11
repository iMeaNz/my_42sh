/*
** EPITECH PROJECT, 2022
** my_42sh
** File description:
** arrows.c
*/

#include <stdio.h>

int get_pos(int *y, int *x);

void arrow_up(int *offset, __attribute__((unused))char **cmd)
{
    //printf("Up arrow\n");
}

void arrow_down(int *offset, __attribute__((unused))char **cmd)
{
    //printf("Down arrow\n");
}

void arrow_right(int *offset, __attribute__((unused))char **cmd)
{
    if (*offset == 0)
        return;
    dprintf(1, "\x1b[C");
    *offset += 1;
}

void arrow_left(int *offset, __attribute__((unused))char **cmd)
{
    int row = 0;
    int col = 0;
    get_pos(&col, &row);
    if (col == 1)
        return;
    dprintf(1, "\x1b[D");
    *offset -= 1;
}