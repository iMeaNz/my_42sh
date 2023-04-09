/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper1-thomas.decaudain
** File description:
** my_putstderr.c
*/

#include <unistd.h>
#include "my.h"

void my_putstderr(char *str)
{
    int len = my_strlen(str);
    write(2, str, len);
}
