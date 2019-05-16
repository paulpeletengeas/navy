/*
** EPITECH PROJECT, 2019
** navy
** File description:
** check if the attack hit a boat or missed it
*/

int is_hit(char *coord, char **map)
{
    if (!coord)
        return (-1);
    else if (map[coord[1] - 47][coord[0] - 63] != '.')
        return (1);
    return (0);
}
