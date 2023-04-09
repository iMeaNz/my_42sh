/*
** EPITECH PROJECT, 2021
** MY_STR_ISNUM
** File description:
** Checks if a string contains only num
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != 0; ++i) {
        if (is_num(str[i]) == 0)
            return 0;
    }
    return 1;
}
