/*
** EPITECH PROJECT, 2018
** bootstrap
** File description:
** read and display n bytes
*/

#include <stdio.h>
#include "get_next_line.h"

int len(char *str)
{
    int index = 0;

    if (!str)
        return (0);
    while (str[index]) {
        index++;
    }
    return (index);
}

int parse(char *buffer)
{
    int index = 0;

    if (!buffer)
        return (0);
    while (buffer[index]) {
        if (buffer[index] == '\n')
            return (index);
        index++;
    }
    return (-1);
}

int trunc_backslash(char **dest, int pos)
{
    char *new_dest = malloc(sizeof(char) * (len(*dest) + 1));
    int index = 0;

    if (!new_dest)
        return (84);
    while (index < pos) {
        new_dest[index] = (*dest)[index];
        index++;
    }
    new_dest[index] = '\0';
    free(*dest);
    *dest = new_dest;
    return (0);
}

int concat(char **dest, char *buffer)
{
    char *new_dest = malloc(sizeof(char) * (len(*dest) + len(buffer) + 1));
    int index = 0;
    int sub_index = 0;

    if (!new_dest) return (84);
    if (*dest) {
        while ((*dest)[sub_index]) {
            new_dest[index++] = (*dest)[sub_index++];
        }
        sub_index = 0;
    }
    if (buffer) {
        while (buffer[sub_index]) {
            new_dest[index++] = buffer[sub_index++];
        }
    }
    new_dest[index] = '\0';
    free(*dest);
    *dest = new_dest;
    return (0);
}

char *get_next_line(int fd)
{
    static char *rest = NULL;
    char *dest = NULL;
    char buffer[READ_SIZE + 1] = {'\0'};
    int pos = -1;
    int size = 0;

    if (fd < 0 || READ_SIZE < 1 || concat(&dest, rest) != 0)
        return (NULL);
    (rest) ? free(rest) : 0;
    rest = NULL;
    while ((pos = parse(dest)) == -1) {
        if (((size = read(fd, buffer, READ_SIZE)) < 0) ||
            concat(&dest, buffer) != 0 || (!buffer[0] && pos < 0))
            return (NULL);
    }
    if (concat(&rest, &dest[pos + 1]) != 0)
        return (NULL);
    return ((trunc_backslash(&dest, pos) != 0) ? NULL : dest);
}
