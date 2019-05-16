/*
** EPITECH PROJECT, 2019
** my_navy
** File description:
** map
*/

#include <unistd.h>
#include "proto.h"

int disp_tab(char **map)
{
    int i = 0;

    while (map[i]) {
        if (my_putstr(map[i++]) || write(1, "\n", 1) == -1)
            return (84);
    }
    if (write (1, "\n", 1) == -1)
        return (84);
    return (0);
}

int display_maps(char **map, char **enemy_map)
{
    if (my_putstr("my positions:\n") ||
        disp_tab(map) ||
        my_putstr("\nenemy's positions:\n") ||
        disp_tab(enemy_map))
        return (84);
    return (0);
}

int mod_map(char **map, char *pos)
{
    int ref[8] = {2, 4, 6, 8, 10, 12, 14, 16};
    int i = pos[1] - 47;
    int j = ref[pos[0] - 65];

    if (i < 2 || i > 9 || j < 2 || j > 16)
        return (84);
    map[i][j] = (map[i][j] != '.') ? 'x' : 'o';
    return (0);
}

int mod_enemy(char **map, int hit, char *pos)
{
    int ref[8] = {2, 4, 6, 8, 10, 12, 14, 16};
    int i = pos[1] - 47;
    int j = ref[pos[0] - 65];

    if (i < 2 || i > 9 || j < 2 || j > 16)
        return (84);
    map[i][j] = (hit == 1) ? 'x' : 'o';
    return (0);
}
