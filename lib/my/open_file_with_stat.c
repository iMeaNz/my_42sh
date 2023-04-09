/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper1-thomas.decaudain
** File description:
** open_file.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"

char *open_file_with_stat(char *path)
{
    struct stat st;
    int fd = open(path, O_RDONLY | 0, 0);
    int size = 0;
    char *buffer;
    int error = 0;

    if (fd == -1 || stat(path, &st) == -1) {
        my_putstderr("There was an error in the file\n");
        return NULL;
    }
    size = st.st_size;
    buffer = init_str(size);
    error = read(fd, buffer, size);
    if (error == -1) {
        my_putstderr("There was an error reading the file\n");
        return NULL;
    }
    buffer[error] = '\0';
    return buffer;
}
