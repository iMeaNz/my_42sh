/*
** EPITECH PROJECT, 2021
** MY_STR_TO_WORD_ARRAY
** File description:
** Splits a string into words
*/

#include <stdlib.h>
#include "my.h"

static int find_number_word(char const *str)
{
    int i = 0;
    int nb_word = 0;
    int in_a_word = 0;

    while (str[i] != '\0') {
        if (is_alpha(str[i]) || is_num(str[i]))
            in_a_word = 1;
        if (in_a_word && !is_alpha(str[i]) && !is_num(str[i])) {
            nb_word++;
            in_a_word = 0;
        }
        i++;
    }

    return nb_word + 1;
}

char **my_str_to_word_array(char const *str)
{
    int number_word = find_number_word(str);
    char **word_array = init_str_array(number_word);
    int count = 0;
    int word = 0;
    int in_a_word = 0;
    int i = 0;

    do {
        if (is_alpha(str[i]) || is_num(str[i])) {
            in_a_word = 1;
            count++;
        } else if (in_a_word) {
            word_array[word] = init_str(count);
            my_strncpy(word_array[word++], &str[i - count], count);
            in_a_word = 0;
            count = 0;
        }
    } while (str[i++] != '\0');
    word_array[word] = 0;
    return word_array;
}
