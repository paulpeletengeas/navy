/*
** EPITECH PROJECT, 2019
** navy
** File description:
** put string on screen
*/

#include <unistd.h>

int my_strlen(char *);

int my_putstr(char *str)
{
    int ret = write(1, str, my_strlen(str));

    return ((ret == -1) ? 84 : 0);
}

int error_str(char *str)
{
    write(2, str, my_strlen(str));
    return (84);
}
