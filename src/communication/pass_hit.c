/*
** EPITECH PROJECT, 2019
** navy
** File description:
** check if hit
*/

#include <unistd.h>
#include <signal.h>
#include "proto.h"

void sig_handler(int sig)
{
    static int trigger = 0;

    if (sig == SIGUSR1) {
        get_data(trigger++);
    } else if (sig == SIGUSR2) {
        trigger = 0;
        get_data(-2);
    }
}

int get_hit(void)
{
    struct sigaction sa;
    int ret = 0;

    sa.sa_handler = &sig_handler;
    sa.sa_flags = SA_RESTART;
    if (sigemptyset(&sa.sa_mask) == -1 ||
        sigaction(SIGUSR1, &sa, NULL) == -1 ||
        sigaction(SIGUSR2, &sa, NULL) == -1) return (84);
    while (get_data(-1) != -2) {
        ret = get_data(-1);
        usleep(1);
    }
    get_data(0);
    return ((ret >= 1) ? 1 : 0);
}

int send_hit(int hit, int pid)
{
    int index = 0;
    int stop = (hit == 1) ? 4 : 1;

    while (index < stop) {
        if (kill(pid, SIGUSR1) == -1) return (84);
        usleep(12500);
        index++;
    }
    if (kill(pid, SIGUSR2) == -1) return (84);
    usleep(12500);
    return (0);
}
