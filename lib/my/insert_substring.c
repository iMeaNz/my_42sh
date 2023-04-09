/*
** EPITECH PROJECT, 2022
** my_42sh
** File description:
** insert_substring.c
*/

#include "my.h"

void insert_substring(char **str, char *substr, int index)
{
    int len = (*str == NULL) ? 0 : strlen(*str);
    if (index < 0 || index > len)
        return;

    int sublen = strlen(substr);
    char *newstr = malloc(sizeof(char) * (len + sublen + 1));
    memset(newstr, 0, sizeof(char) * (len + sublen + 1));
    if (*str != NULL)
        memcpy(newstr, *str, index);
    memcpy(newstr + index, substr, sublen);
    if (*str != NULL)
        memcpy(newstr + index + sublen, *str + index, len - index + 1);
    else
        newstr[sublen] = '\0';
    free(*str);
    *str = newstr;
}

