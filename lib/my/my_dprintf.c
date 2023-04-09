/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** my_dprintf.c
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static void compute_percent(char id, va_list ap, int fd)
{
    if (id == 'd')
        my_dput_nbr(va_arg(ap, int), fd);
    if (id == 'c') {
        char output = va_arg(ap, int);
        write(fd, &output, 1);
    }
    if (id == 's') {
        char *output = va_arg(ap, char *);
        write(fd, output, my_strlen(output));
    }
}

void my_dprintf(int fd, char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i] != 0; ++i) {
        if (str[i] == '%' && str[i + 1] != '%') {
            compute_percent(str[++i], ap, fd);
            continue;
        }
        if (str[i] == '%' && str[i + 1] == '%')
            write(fd, "%", 1);
        else
            write(fd, &str[i], 1);
    }
    va_end(ap);
}
