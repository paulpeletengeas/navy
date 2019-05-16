/*
** EPITECH PROJECT, 2019
** navy
** File description:
** contain functions prototypes
*/

#ifndef _MY_H_
#define _MY_H_

int try_connect(int);
int wait_player2(void);
char **load_map(char const *);
int my_strlen(char *);
int my_putstr(char *);
int my_put_nbr(int);
int my_atoi(char *);
int error_str(char *);
int is_alpha(char *);
int game_loop(char **, char **, int, int);
char **create_map(char **);
int write_map(int, char **);
int connect(int, int);
int check_entry(char *);
int pass_coord(char *, int);
char *get_coord(void);
int is_hit(char *, char **);
int send_hit(int, int);
int get_hit(void);
int display_maps(char **, char **);
int mod_map(char **, char *);
int mod_enemy(char **, int, char *);
int get_data(int);

#endif //_MY_H_
