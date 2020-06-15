/*
** EPITECH PROJECT, 2024
** AIA_n4s_2019
** File description:
** Created by Enzo Ventura
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "n4s.h"

char **get_info_lidar(char *buf)
{
    char **tab;
    size_t size = 0;

    write(1, "GET_INFO_LIDAR\n", 15);
    getline(&buf, &size, stdin);
    tab = my_str_to_word_array(buf, ":", 22);
    return tab;
}

void ai(void)
{
    t_ai *ai = malloc(sizeof(t_ai));

    ai->linebuf = NULL;
    while (1) {
        ai->lidar = get_info_lidar(ai->linebuf);
        throttle(ai);
        if (exec_cmd(set_throttle(ai)) == END) {
            break;
        }
        turn_wheels(get_turn_from_lidar(ai));
    }
}

int main(void)
{
    if (exec_cmd("START_SIMULATION\n") == 1)
        return 0;
    ai();
    return 0;
}