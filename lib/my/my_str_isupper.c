/*
** EPITECH PROJECT, 2021
** MY_STR_ISUPPER
** File description:
** Checks if a string contains only uppercase
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != 0; ++i) {
        if (is_upper(str[i]) == 0)
            return 0;
    }
    return 1;
}
