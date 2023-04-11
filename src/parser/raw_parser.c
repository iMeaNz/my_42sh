/*
** EPITECH PROJECT, 2022
** my_42sh
** File description:
** parser.c
*/

#include "my.h"
#include "shell.h"
#include <termios.h>

void arrow_up(int *offset, char **cmd);
void arrow_down(int *offset, char **cmd);
void arrow_left(int *offset, char **cmd);
void arrow_right(int *offset, char **cmd);
void backspace(int *offset, char **cmd);
void suppr(int *offset, char **cmd);
void main_parser(sh_data_t *sh, char *raw_cmd);
int get_pos(int *y, int *x);

static const char *escape_sequences[] = {
    "\x1b[A", //up arrow
    "\x1b[B", //down arrow
    "\x1b[C", //right arrow
    "\x1b[D", //left arrow
    "\x1b[3~", //suppr key
    "\x7f", //backspace key
};

static void (*const escape_function[])(int *, char **) = {
    &arrow_up, //up arrow
    &arrow_down, //down arrow
    &arrow_right, //right arrow
    &arrow_left, //left arrow
    &suppr, //suppr key
    &backspace, //backspace key
};

struct termios init_terminal(void)
{
    struct termios orig_term_attr;
    tcgetattr(0, &orig_term_attr);
    struct termios new_term_attr = orig_term_attr;
    new_term_attr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &new_term_attr);
    return orig_term_attr;
}

void found_breakline(sh_data_t *sh, char **cmd, char *buffer, int *offset)
{
    memset(buffer, 0, 1024);
    main_parser(sh, *cmd);
    if (cmd && *cmd)
        free(*cmd);
    *cmd = NULL;
    *offset = 0;
}

int check_for_escape_sequence(char **cmd, char *buffer, int *offset)
{
    for (int i = 0; i < 6; ++i) {
        if (strstr(buffer, escape_sequences[i]) != NULL) {
            escape_function[i](offset, cmd);
            memset(buffer, 0, 1024);
            return 1;
        }
    }
    return 0;
}

void insert_input_to_cmd(char **cmd, char *buffer, int offset)
{
    int row = 0;
    int col = 0;
    int len = (cmd != NULL && *cmd != NULL) ? strlen(*cmd) : 0;
    insert_substring(cmd, buffer, len + offset);
    char *tmp = *cmd;
    get_pos(&col, &row);
    write(1, &tmp[strlen(tmp) + offset - 1],
                strlen(&tmp[strlen(tmp) + offset - 1]));
    if (buffer[0] != '\t')
        dprintf(1, "\033[%d;%dH", row, col + 1);
    memset(buffer, 0, 1024);
}

void raw_parser(sh_data_t *sh)
{
    char buffer[1024] = {0};
    struct termios orig_term_attr = init_terminal();
    char *cmd = NULL;
    int offset = 0;
    while (read(0, &buffer, 1024) != 0 || errno == EAGAIN) {
        if (buffer[0] == 4)
            return;
        if (!buffer[0])
            continue;
        if (strchr(buffer, '\n')) {
            found_breakline(sh, &cmd, buffer, &offset);
            continue;
        }
        if (check_for_escape_sequence(&cmd, buffer, &offset))
            continue;
        insert_input_to_cmd(&cmd, buffer, offset);
    }
}