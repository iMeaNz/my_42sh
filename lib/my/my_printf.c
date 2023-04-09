/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** my_printf.c
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

static void compute_percent(char id, va_list ap)
{
    if (id == 'd')
        my_put_nbr(va_arg(ap, int));
    if (id == 'c')
        my_putchar(va_arg(ap, int));
    if (id == 's')
        my_putstr(va_arg(ap, char *));
}

void my_printf(char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i] != 0; ++i) {
        if (str[i] == '%' && str[i + 1] != '%') {
            compute_percent(str[++i], ap);
            continue;
        }
        if (str[i] == '%' && str[i + 1] == '%')
            my_putchar(str[i++]);
        else
            my_putchar(str[i]);
    }
    va_end(ap);
}
