/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** my_dput_nbr.c
*/

#include "my.h"
#include <unistd.h>

int my_dput_nbr(int nb, int fd)
{
    int modulo = 0;

    if (nb == -2147483648) {
        write(fd, "-2147483648", 11);
        return 0;
    }
    if (nb < 0) {
        char minus = '-';
        write(fd, &minus, 1);
        nb *= -1;
    }
    modulo = nb % 10 + '0';
    nb /= 10;
    if (nb > 0)
        my_put_nbr(nb);
    write(fd, &modulo, 1);
}
