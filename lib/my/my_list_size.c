/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** size_linked_list.c
*/

#include "my.h"
#include "linked_list.h"
#include <stdlib.h>

int my_list_size(linked_list_t *list)
{
    int size = 0;

    while (list != NULL) {
        size++;
        list = list->next;
    }
    return size;
}
