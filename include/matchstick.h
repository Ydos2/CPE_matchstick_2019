/*
** EPITECH PROJECT, 2020
** ls
** File description:
** ls
*/

#ifndef LS_H_
#define LS_H_
#include <stdio.h>

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
} map_t;

int matchstick(int argc, char **argv);
void initialise_var(map_t *map, char **argv);
void initialise_change_player(map_t *map);
void set_change_player(map_t *map, int z);

void initialise_map(map_t *map);
void set_map(map_t *map, int x, int y);

void print_updated_board_game(map_t *map);
void set_Line(map_t *map, char *line, size_t len, int error);
void set_Matches(map_t *map, char *line, size_t len, int error);

int my_atoi(char *str);
int my_putstr(char const *str);
int my_strlenn(char const *str);

#endif /* !LS_H_ */