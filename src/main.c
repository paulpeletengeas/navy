/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main function
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "proto.h"

void my_free(char **map, char **enemy_map)
{
    int index = 0;

    while (map[index]) {
        free(map[index++]);
    }
    free(map);
    index = 0;
    while (enemy_map[index]) {
        free(enemy_map[index++]);
    }
    free(enemy_map);
}

int disp_h(void)
{
    my_putstr("USAGE:\n\t./navy [pid] <pos>\n\n");
    my_putstr("DESCRIPTION:\n\tpid\tpid of the first player (only 2nd");
    my_putstr(" player)\n\tpos\tPositions of the ships\n");
    return (0);
}

int main(int ac, char **av)
{
    int pid = 0;
    char **map = NULL;
    char **enemy_map = NULL;
    const int map_pos = (ac == 2) ? 1 : 2;

    if (ac < 2 || ac > 3) return (disp_h());
    if (!(enemy_map = create_map(enemy_map)) ||
        !(map = load_map(av[map_pos])) ||
        (pid = connect(ac, ((ac == 3) ? my_atoi(av[1]) : 0))) == 84 ||
        game_loop(map, enemy_map, pid, map_pos))
        return (84);
    my_free(map, enemy_map);
    return (0);
}
