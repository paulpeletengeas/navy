/*
** EPITECH PROJECT, 2019
** navy
** File description:
** write boat into map
*/

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "struct_map.h"
#include "proto.h"

int check_format(char *line)
{
    int len = my_strlen(line);

    if (len != 8) return (84);
    if (line[1] != ':' || line[4] != ':') return (84);
    if ((line[0] < '1' || line[0] > '8') || (line[3] < '1' || line[3] > '8') ||
        (line[6] < '1' || line[6] > '8')) return (84);
    if ((line[2] < 'A' || line[2] > 'H') || (line[5] < 'A' || line[5] > 'H'))
        return (84);
    return (0);
}

void add_boat(char *line, char **map)
{
    coef_t coef = {
        ((line[2] == line[5]) ? 1 : 0),
        ((line[2] == line[5]) ? 0 : 2)
    };
    int index = 0;
    int i = 0;
    int j = 0;

    while (map[0][j] != line[2])
        j++;
    while (map[i][0] != line[3])
        i++;
    map[i][j] = line[0];
    while (index < line[0] - 49) {
        map[i += coef.i][j += coef.j] = line[0];
        index++;
    }
}

int write_map(int fd, char **map)
{
    char *line = NULL;
    int index = 0;
    int base[4] = {2, 3, 4, 5};

    while ((line = get_next_line(fd))) {
        if (check_format(line) || index > 3 || base[index] != (line[0] - 48))
            return (error_str("Invalid map\n"));
        add_boat(line, map);
        free(line);
        index++;
    }
    return (close(fd));
}
