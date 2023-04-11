/*
** EPITECH PROJECT, 2022
** my_42sh
** File description:
** signals.c
*/

#include <signal.h>
#include <unistd.h>

void handle_interrupt(__attribute__((unused)) int signal)
{
    write(1, "\n", 1);
}

void sig_handler(void)
{
    signal(SIGINT, handle_interrupt);
}