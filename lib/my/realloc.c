/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** realloc.c
*/

#include "my.h"

void *my_realloc(void *ptr, size_t size)
{
    if (!ptr)
        return malloc(size);
    if (!size) {
        free(ptr);
        return NULL;
    }
    void *new_ptr = malloc(size);
    if (!new_ptr)
        return NULL;
    size_t old_size = sizeof(ptr);
    size_t copy_size = old_size < size ? old_size : size;
    memcpy(new_ptr, ptr, copy_size);
    free(ptr);
    return new_ptr;
}
