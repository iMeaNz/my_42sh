/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** print_linked_list.c
*/

#include "my.h"
#include "linked_list.h"
#include <stdlib.h>

void print_linked_list(linked_list_t *list)
{
    while (list != NULL) {
        my_printf("%s\n", list->data);
        list = list->next;
    }
}
