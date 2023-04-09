/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** my_strtok_alpha.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strtok_alpha(char *string)
{
    static char *iter_str = "";
    int i = 0;
    int j = 0;

    if (string != NULL) {
        for (; string[j] && !is_alpha(string[j]) ; ++j);
        iter_str = &string[j];
    }
    char *start = iter_str;
    for (; iter_str[i] && is_alpha(iter_str[i]) ; ++i);
    iter_str = &iter_str[i];
    int a = 0;
    for (; iter_str[a] && !is_alpha(iter_str[a]) ; ++a)
        iter_str[a] = '\0';
    if (start[0] == '\0')
        return (NULL);
    iter_str = &iter_str[a];
    return (start);
}
