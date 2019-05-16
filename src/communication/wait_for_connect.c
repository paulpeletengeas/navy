/*
** EPITECH PROJECT, 2019
** navy
** File description:
** wait the player 2 to connect to the process
*/

#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "proto.h"

int player2_pid = -1;

void get_pid(int sig, siginfo_t *info, void *context)
{
    (void)context;
    if (sig == 10)
        player2_pid = info->si_pid;
}

void verif(int sig)
{
    if (sig == 10)
        my_putstr("successfully connected\n\n");
}

int try_connect(int pid)
{
    struct sigaction sig;

    sig.sa_flags = SA_RESTART;
    sig.sa_handler = &verif;
    if (sigemptyset(&sig.sa_mask) == -1 || sigaction(10, &sig, NULL) == -1 ||
        my_putstr("my_pid:\t") || my_put_nbr(getpid()) || my_putstr("\n") ||
        kill(pid, 10) == -1)
        return (84);
    pause();
    return (pid);
}

int wait_player2(void)
{
    struct sigaction sig;

    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = get_pid;
    if (sigemptyset(&sig.sa_mask) == -1 || sigaction(SIGUSR1, &sig, NULL) == -1)
        return (84);
    if (my_putstr("my_pid:\t") || my_put_nbr(getpid()) ||
        my_putstr("\nwaiting for enemy connection\n\n"))
        return (84);
    pause();
    if (my_putstr("enemy connected\n\n") || kill(player2_pid, 10) == -1)
        return (84);
    return (player2_pid);
}

int connect(int player, int pid)
{
    if (player == 2)
        return (wait_player2());
    else
        return (try_connect(pid));
    return (84);
}
