/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** my_sort_list.c
*/

#include "my.h"
#include "linked_list.h"
#include <stdlib.h>

static linked_list_t *my_swap_node(linked_list_t *ptr)
{
    linked_list_t *tmp;
    linked_list_t *new_ptr;

    new_ptr = ptr->next;
    tmp = ptr->next->next;
    ptr->next->next = ptr;
    ptr->next = tmp;
    return new_ptr;
}

void compare_node(int *sorted, int (*cmp)(char const *, char const *),
                linked_list_t *ptr)
{
    if ((*cmp)(ptr->next->data,
        ptr->next->next->data) > 0) {
        ptr->next = my_swap_node(ptr->next);
        *sorted = 0;
    }
}

void my_sort_list(linked_list_t **begin)
{
    int sorted = 0;
    linked_list_t *ptr;
    int (*cmp)(char const *, char const *) = &my_strcmp;

    if (my_list_size(*begin) <= 1)
        return;
    while (!sorted) {
        sorted = 1;
        if (cmp((*begin)->data, (*begin)->next->data) > 0) {
            *begin = my_swap_node(*begin);
        }
        ptr = *begin;
        while (ptr->next->next != NULL) {
            compare_node(&sorted, cmp, ptr);
            ptr = ptr->next;
        }
    }
}
