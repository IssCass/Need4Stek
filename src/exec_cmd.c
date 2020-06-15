/*
** EPITECH PROJECT, 2024
** AIA_n4s_2019
** File description:
** Created by Enzo Ventura
*/

#include "n4s.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int exec_cmd(char *cmd)
{
    size_t len = 0;

    write(1, cmd, strlen(cmd));
    getline(&cmd, &len, stdin);
    if (strlen(cmd) == 1 && cmd[0] == '\n')
        return 1;
    if (check_end(cmd) == TRUE) {
        free(cmd);
        return END;
    }
    return 0;
}