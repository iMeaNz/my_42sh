/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** append_in_linked_list.c
*/

#include "my.h"
#include "linked_list.h"
#include <stdlib.h>

void append_in_linked_list(linked_list_t **list, char *data)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));
    linked_list_t *last = (*list);

    if (new == NULL)
        return;
    new->data = data;
    new->next = NULL;
    if ((*list) == NULL) {
        (*list) = new;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new;
}
