/*
** EPITECH PROJECT, 2019
** navy
** File description:
** give coord of the attack to enemy
*/

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "proto.h"
#include "struct_map.h"

int get_data(int value)
{
    static int data = 0;

    if (value != -1)
        data = value;
    else
        return (data);
    return (0);
}

void handler(int sig)
{
    static int trigger = 0;

    if (sig == SIGUSR1) {
        get_data(trigger++);
    } else if (sig == SIGUSR2) {
        trigger = 0;
        get_data(-2);
    }
}

char *format(int y, int x)
{
    char *dest = malloc(sizeof(char) * 3);

    if (!dest)
        return (NULL);
    dest[0] = y + 64;
    dest[1] = x + 48;
    dest[2] = '\0';
    return (dest);
}

char *get_coord(void)
{
    struct sigaction receiver;
    int x = 0;
    int y = 0;

    if (my_putstr("Waiting for enemy's attack...\n")) return (NULL);
    receiver.sa_handler = &handler;
    receiver.sa_flags = SA_RESTART;
    if (sigemptyset(&receiver.sa_mask) == -1 ||
        sigaction(SIGUSR1, &receiver, NULL) == -1 ||
        sigaction(SIGUSR2, &receiver, NULL) == -1) return (NULL);
    while (get_data(-1) != -2) {
        y = get_data(-1);
        usleep(1);
    }
    get_data(0);
    while (get_data(-1) != -2) {
        x = get_data(-1);
        usleep(1);
    }
    get_data(0);
    return (format(y + 1, x + 1));
}

int pass_coord(char *coord, int pid)
{
    int index = -1;

    while (++index < (coord[0] - 64)) {
        if (kill(pid, SIGUSR1) == -1) return (84);
        usleep(12500);
    }
    if (kill(pid, SIGUSR2) == -1) return (84);
    usleep(12500);
    index = -1;
    while (++index < (coord[1] - 48)) {
        if (kill(pid, SIGUSR1) == -1) return (84);
        usleep(12500);
    }
    if (kill(pid, SIGUSR2) == -1) return (84);
    usleep(12500);
    pause();
    return (0);
}
