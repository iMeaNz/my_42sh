/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** delete_node.c
*/

#include "my.h"
#include "linked_list.h"
#include <stdlib.h>

void delete_node_with_key(linked_list_t **list, char *key)
{
    linked_list_t *tmp = (*list);
    linked_list_t *prev = (*list);

    if (tmp != NULL && !my_strcmp(tmp->data, key)) {
        (*list) = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && my_strcmp(tmp->data, key)) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    prev->next = tmp->next;
    free(tmp);
}
