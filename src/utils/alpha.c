/*
** EPITECH PROJECT, 2019
** navy
** File description:
** function that check if string contain letter
*/

int is_alpha(char *str)
{
    int index = 0;

    while (str[index]) {
        if (str[index] < '0' || str[index] > '9') return (-1);
        index++;
    }
    return (0);
}
