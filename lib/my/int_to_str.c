/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** int_to_str.c
*/

#include "my.h"
#include <stdlib.h>

static int size_nb(int nb)
{
    int size = 0;
    while (nb != 0) {
        nb /= 10;
        size++;
    }
    return size;
}

char *int_to_str(int nb)
{
    int size = size_nb(nb);
    char *output = init_str(size);

    if (output == NULL)
        return NULL;
    my_sput_nbr(nb, output);
    return output;
}
