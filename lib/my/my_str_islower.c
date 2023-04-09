/*
** EPITECH PROJECT, 2021
** MY_STR_ISLOWER
** File description:
** Checks if a string contains only lowercase
*/

#include "my.h"

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != 0; ++i) {
        if (is_lower(str[i]) == 0)
            return 0;
    }
    return 1;
}
