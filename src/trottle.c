/*
** EPITECH PROJECT, 2024
** AIA_n4s_2019
** File description:
** Created by Leo Fabre
*/
#include "n4s.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

float get_smallest_distance(t_ai *ai)
{
    float min = atof(ai->lidar[0]);
    float cur = 0.f;

    for (int i = 0; ai->lidar[i]; ++i) {
        cur = atof(ai->lidar[i]);
        if (cur < min)
            min = cur;
    }
    return min;
}

char *set_throttle(t_ai *ai)
{
    char buf[10];
    char *command = NULL;

    dprintf(2, "Min distance: %f\n", get_smallest_distance(ai));
    dprintf(2, "Calculated throttle: %f\n", ai->throttle);
    sprintf(buf, "%.3f\n", ai->throttle);
    command = my_strcat("CAR_FORWARD:", buf);
    return (command);
}

void throtlle_three(t_ai *ai, float lidar_mid)
{
    if (lidar_mid >= 300)
        ai->throttle = 0.2f;
    else
        ai->throttle = 0.1f;
}

void throttle_two(t_ai *ai, float lidar_mid)
{
    if (lidar_mid >= 800)
        ai->throttle = 0.5f;
    else if (lidar_mid >= 400)
        ai->throttle = 0.4f;
    else
        throtlle_three(ai, lidar_mid);
}

void throttle(t_ai *ai)
{
    float lidar_mid = atof(ai->lidar[15]);

    if (lidar_mid >= 1800)
        ai->throttle = 1.0f;
    else if (lidar_mid >= 1200)
        ai->throttle = 0.8f;
    else
        throttle_two(ai, lidar_mid);
}