/*
** EPITECH PROJECT, 2018
** myputnbr
** File description:
** print un integer
*/

#include <unistd.h>

int my_putchar(char c)
{
    return (write(1, &c, 1));
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        if (my_putchar('-') == -1)
            return (84);
        nb = nb * (-1);
        my_put_nbr(nb);
    } else if (nb <= 9) {
        if (my_putchar(nb + 48) == -1)
            return (84);
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (0);
}
