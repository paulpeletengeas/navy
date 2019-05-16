/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** game_loop
*/

#include "get_next_line.h"
#include "proto.h"
#include "struct_map.h"

char *get_attack(void)
{
    char *ret = NULL;

    my_putstr("attack:\t");
    ret = get_next_line(0);
    if (check_entry(ret) != 0) {
        my_putstr("Wrong position\n");
        return (NULL);
    }
    return (ret);
}

int print_attack(char *entry, int hit)
{
    if (hit == 84)
        return (84);
    if (my_putstr(entry) == -1 ||
        my_putstr(":\t") == -1 ||
        my_putstr((hit == 1) ? "hit" : "missed") == -1 ||
        my_putstr("\n\n") == -1)
        return (84);
    return (0);
}

int game_loop(char **map, char **enemy_map, int pid, int player)
{
    char *entry = NULL;
    char *attack_pos = NULL;
    int hit1 = 0;
    int hit2 = 0;
    int end = 0;

    while (!end) {
        if (display_maps(map, enemy_map)) return (84);
        if (player == 1) {
            while (!(entry = get_attack()));
            if (pass_coord(entry, pid) ||
                print_attack(entry, (hit1 = get_hit())) ||
                mod_enemy(enemy_map, hit1, entry)) return (84);
        } else {
            if ((hit2 = is_hit((attack_pos = get_coord()), map)) == -1 ||
                mod_map(map, attack_pos) || send_hit(hit2, pid) ||
                print_attack(attack_pos, hit2)) return (84);
        }
        player = (player == 1) ? 2 : 1;
    }
    return (0);
}
