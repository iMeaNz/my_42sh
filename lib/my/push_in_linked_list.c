/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** add_in_linked_list.c
*/

#include "my.h"
#include "linked_list.h"
#include <stdlib.h>

void push_in_linked_list(linked_list_t **list, char *data)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));
    new->data = data;
    new->next = (*list);
    (*list) = new;
}
