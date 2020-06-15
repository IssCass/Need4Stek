/*
** EPITECH PROJECT, 2024
** AIA_n4s_2019
** File description:
** Created by Enzo Ventura
*/

#include "n4s.h"
#include <stdlib.h>

double get_turn_three(float lidar_mid, float lidar_delta)
{

    if (lidar_mid >= 200) {
        dprintf(2, ">= 200\n");
        return (lidar_delta > 0.0 ? 0.3 : -0.3);
    }
    dprintf(2, "else\n");
    return (lidar_delta > 0.0 ? 0.6 : -0.6);
}

double get_turn_two(float lidar_mid, float lidar_delta)
{
    if (lidar_mid >= 600) {
        dprintf(2, ">= 600\n");
        return (lidar_delta > 0.0 ? 0.1 : -0.1);
    } else if (lidar_mid >= 400) {
        dprintf(2, ">= 400\n");
        return (lidar_delta > 0.0 ? 0.2 : -0.2);
    }
    return get_turn_three(lidar_mid, lidar_delta);
}

double get_turn_one(float lidar_mid, float lidar_delta)
{
    if (lidar_mid >= 2000) {
        dprintf(2, ">= 2000\n");
        return (lidar_delta / 3010) / 6;
    } else if (lidar_mid >= 1000) {
        dprintf(2, ">= 1000\n");
        return (lidar_delta > 0.0 ? 0.05 : -0.05);
    }
    return get_turn_two(lidar_mid, lidar_delta);
}

double get_turn_from_lidar(t_ai *ai)
{
    float lidar_left = atof(ai->lidar[0]);
    float lidar_right = atof(ai->lidar[31]);
    float lidar_mid = atof(ai->lidar[15]);
    float lidar_delta = lidar_left - lidar_right;

    return get_turn_one(lidar_mid, lidar_delta);
}

void turn_wheels(double angle)
{
    char buf[10];
    char *command = NULL;

    sprintf(buf, "%.3f\n", angle);
    command = my_strcat("WHEELS_DIR:", buf);
    dprintf(2, "turn = %s\n", command);
    exec_cmd(command);
}