/*
** EPITECH PROJECT, 2024
** AIA_n4s_2019
** File description:
** Created by Enzo Ventura
*/

#include "n4s.h"
#include <string.h>
#include <unistd.h>

int check_end(char *str)
{
    char **array = my_str_to_word_array(str, ":", 0);

    for (int i = 0; array[i]; i++) {
        if (strcmp(array[i], "Track Cleared") == 0) {
            free_tab(array);
            write(1, "CAR_FORWARD:0\n", 14);
            write(1, "STOP_SIMULATION\n", 16);
            return TRUE;
        }
    }
    free_tab(array);
    return FALSE;
}