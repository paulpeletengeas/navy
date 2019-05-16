/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** str to int
*/

int my_strlen(char const *);

int int_len(int nb)
{
    int res = 0;

    while (nb > 0) {
        nb = nb / 10;
        res++;
    }
    return (res);
}

int digit_len(char *str)
{
    int index = 0;
    int res = 0;

    if (!str)
        return (-1);
    while (str[index]) {
        if (str[index] < 48 || str[index] > 57)
            return (res);
        index++;
        res++;
    }
    return (res);
}

int get_coef(int stop)
{
    int coef = 1;

    if (stop == -1)
        return (-1);
    while (int_len(coef) < stop) {
        coef *= 10;
    }
    return (coef);
}

int my_atoi(char *str)
{
    int res = 0;
    int stop = digit_len(str);
    int coef = get_coef(stop);
    int index = 0;

    if (stop == -1 || coef == -1)
        return (-1);
    while (index < stop) {
        res += (str[index] - 48) * coef;
        coef /= 10;
        index++;
    }
    return (res);
}
