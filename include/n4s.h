/*
** EPITECH PROJECT, 2024
** AIA_n4s_2019
** File description:
** Created by Enzo Ventura
*/

#ifndef AIA_N4S_2019_N4S_H
#define AIA_N4S_2019_N4S_H

#include <stdio.h>
#include "my.h"

#define FALSE 0
#define TRUE 1
#define END 2

#define RESET              "\x1b[0m"
#define BLACK              "\x1b[30m"
#define RED                "\x1b[31m"
#define GREEN              "\x1b[32m"
#define YELLOW             "\x1b[33m"
#define BLUE               "\x1b[34m"
#define MAGENTA            "\x1b[35m"
#define CYAN               "\x1b[36m"
#define WHITE              "\x1b[37m"

typedef struct s_ai {
    float turn;
    float throttle;
    char **lidar;
    char *linebuf;
} t_ai;

double get_turn_from_lidar(t_ai *ai);
void turn_wheels(double angle);
int exec_cmd(char *cmd);
int check_end(char *str);
void throttle(t_ai *ai);
char *set_throttle(t_ai *ai);

#endif //AIA_N4S_2019_N4S_H
