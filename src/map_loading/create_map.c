/*
** EPITECH PROJECT, 2019
** navy
** File description:
** create an empty map
*/

#include <stdlib.h>

char *create_line(int i, char *letter)
{
    char *map = NULL;
    int j = 0;

    if (!(map = malloc(sizeof(char) * 19))) return (NULL);
    while (j < 17) {
        if ((j > 1 && i == 0) && j % 2 == 0) map[j++] = (*letter)++;
        if (j == 0 && i > 1) map[j++] = (i + 47);
        if (i != 1 && j == 1) map[j++] = '|';
        if ((j >= 1 && i > 1) && j % 2 == 0) map[j++] = '.';
        if (j != 1 && i == 1) map[j++] = '-';
        else if (j != 2 && j != 17) map[j++] = ' ';
        if (j == 1 && i == 1) map[j++] = '+';
    }
    map[j] = '\0';
    return (map);
}

char **create_map(char **map)
{
    int i = 0;
    char letter = 'A';

    if (!(map = malloc(sizeof(char *) * 11))) return (NULL);
    while (i < 10) {
        if (!(map[i] = create_line(i, &letter)))
            return (NULL);
        i++;
    }
    map[i] = NULL;
    return (map);
}
