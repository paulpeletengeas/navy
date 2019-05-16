/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** check_entry
*/

#include "proto.h"

int check_entry(char *entry)
{
    if (my_strlen(entry) != 3) return (1);
    if ((entry[0] < 'A' || entry[0] > 'H')
        || (entry[1] < '1' || entry[1] > '8'))
        return (1);
    return (0);
}