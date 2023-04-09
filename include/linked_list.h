/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST
    #define LINKED_LIST

    typedef struct linked_list {
        char *data;
        struct linked_list *next;
    } linked_list_t;

    void append_in_linked_list(linked_list_t **list, char *data);
    void push_in_linked_list(linked_list_t **list, char *data);
    void print_linked_list(linked_list_t *list);
    void delete_node_with_key(linked_list_t **list, char *key);
    int my_list_size(linked_list_t *list);
    void my_rev_list(linked_list_t **begin);
    void my_sort_list(linked_list_t **begin);
#endif
