/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matchstick
*/

#ifndef LS_H_
#define LS_H_
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <time.h>

typedef struct map
{
    int *tab;
    int size;
    int max_get_stick;
    int x;
    int y;
    int stick_max;
    int stick_min;
    char **map_element;
    int line_select;
    int matches_select;
    int quit_val;
    int error_matches;
} map_t;

// matchstick.c
int my_matchstick(int argc, char **argv, map_t *map);
void initialise_var(map_t *map, char **argv);
void initialise_change_player(map_t *map);
void set_change_player(map_t *map, int z);
map_t *initialise_start(map_t *map, char **argv);

// map.c
void initialise_map(map_t *map);
void set_map(map_t *map, int x, int y);

// draw.c
void print_updated_board_game(map_t *map);
int set_line(map_t *map, char *line, size_t len, int error);
void get_line(map_t *map, int error);
int set_matches(map_t *map, char *line, size_t len);
int draw_matches(map_t *map, char *line);

// tools_function.c
int my_atoi(char *str);
int my_putstr(char const *str);
int my_strlenn(char const *str);
void my_put_nbrr(int nbr);
void my_putcharr(char c);

// victory.c
int set_win(map_t *map);
int set_lose(map_t *map);
void set_end(map_t *map);
void my_free_array(char **array);

// error.c
int get_number_matches(map_t *map, char *line);
int get_first_error(char *line);

// update_game.c
int set_update(int quit, int set_error, map_t *map);
void set_update_matches(map_t *map);

// ai.c
int set_rand_a_b(int a, int b);
void initialise_AI(map_t *map);
void set_ai_order(map_t *map);
void set_AI(map_t *map);

#endif /* !LS_H_ */