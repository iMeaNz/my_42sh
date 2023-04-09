/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** my_sprintf.c
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

static void compute_percent(char id, va_list ap, char *dest)
{
    if (id == 'd') {
        char *to_append = int_to_str(va_arg(ap, int));
        my_strcat(dest, to_append);
    }
    if (id == 'c')
        dest[my_strlen(dest)] = va_arg(ap, int);
    if (id == 's')
        my_strcat(dest, va_arg(ap, char *));
}

void my_sprintf(char *dest, char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '%' && str[i + 1] != '%') {
            compute_percent(str[++i], ap, dest);
            continue;
        }
        if (str[i] == '%' && str[i + 1] == '%')
            my_strcat(dest, "%");
        else
            my_strncat(dest, &str[i], 1);
    }
}
