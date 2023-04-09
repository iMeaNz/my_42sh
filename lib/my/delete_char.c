/*
** EPITECH PROJECT, 2022
** my_42sh
** File description:
** delete_char.c
*/

#include "my.h"

void delete_char_at_index(char *str, int index)
{
    int len = strlen(str);
    if (index >= 0 && index < len)
        memmove(&str[index], &str[index + 1], len - index);
}