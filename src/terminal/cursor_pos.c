/*
** EPITECH PROJECT, 2022
** my_42sh
** File description:
** cursor_pos.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int get_pos(int *y, int *x)
{
    char buf[30] = {0};
    int i = 0;

    write(1, "\033[6n", 4);
    for(char ch = 0; ch != 'R';) {
        int valread = read(0, &ch, 1);
        if (valread == -1 && errno == EAGAIN)
            continue;
        if (!valread)
            return 1;
        buf[i++] = ch;
    }
    int pos_escape = 0;
    for (; buf[pos_escape] != '\033'; pos_escape++);

    if (sscanf(&buf[pos_escape], "\033[%d;%dR", x, y) != 2)
        return 1;
    fflush(stdout);
    return 0;
}