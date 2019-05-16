/*
** EPITECH PROJECT, 2019
** navy
** File description:
** return string lenght
*/

int my_strlen(char *str)
{
    int index = 0;

    if (!str) return (0);
    while (str[index++]);
    return (index);
}
