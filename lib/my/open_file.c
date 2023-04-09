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

char *open_file(char *path)
{
    int fd = open(path, O_RDONLY | 0, 0);
    char *buffer = init_str(1000);
    int error;
    int i = 0;

    while ((error = read(fd, &buffer[i++], 1)) == 1) {
        if (error == -1) {
            my_putstderr("There was an error reading the file\n");
            return NULL;
        }
    }
    return buffer;
}
