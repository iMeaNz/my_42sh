/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** my_sput_nbr.c
*/

#include "my.h"

int my_sput_nbr(int nb, char *str)
{
    int modulo = 0;

    if (nb == -2147483648) {
        my_strcat(str, "-2147483648");
        return 0;
    }
    if (nb < 0) {
        str[my_strlen(str)] = '-';
        nb *= -1;
    }
    modulo = nb % 10 + '0';
    nb /= 10;
    if (nb > 0)
        my_put_nbr(nb);
    str[my_strlen(str)] = modulo;
}
