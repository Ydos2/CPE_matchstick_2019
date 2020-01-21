/*
** EPITECH PROJECT, 2020
** draw
** File description:
** draw
*/

#include "matchstick.h"

void print_updated_board_game(map_t *map)
{
    for (int y = 0; y != map->y; y++) {
        my_putstr(map->map_element[y]);
        write(1, "\n", 1);
    }
}

int set_line(map_t *map, char *line, size_t len, int error)
{
    int ret = 0;

    get_line(map, error);
    ret = getline(&line, &len, stdin);
    if (ret == -1)
        return (-1);
    if (get_number_matches(map, line) == 1)
        set_line(map, line, len, 1);
    map->line_select = my_atoi(line);
    if (map->y-1 <= map->line_select || map->line_select <= 0)
        set_line(map, line, len, 2);
    return (0);
}

void get_line(map_t *map, int error)
{
    if (error == 0) {
        if (map->error_matches == 0)
            print_updated_board_game(map);
        write(1, "\nYour turn:\nLine: ", 18);
        map->error_matches = 0;
    } else if (error == 2) {
        write(1, "Error, this line is out of range\n", 33);
        write(1, "Line: ", 6);
    } else
        write(1, "Line: ", 6);
}

int set_matches(map_t *map, char *line, size_t len)
{
    write(1, "Matches: ", 9);
    if (getline(&line, &len, stdin) == -1)
        return (-1);
    if (draw_matches(map, line) == 1)
        return (1);
    map->matches_select = my_atoi(line);
    if (map->max_get_stick < map->matches_select) {
        write(1, "Error: you cannot remove more than ", 36);
        my_put_nbrr(map->max_get_stick);
        write(1, " matches per turn\n", 18);
        return (1);
    }
    if (map->matches_select > map->tab[map->line_select]) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (1);
    } else
        set_update_matches(map);
    return (0);
}

int draw_matches(map_t *map, char *line)
{
    if (line[0] == '\n') {
        write(1, "Error: you have to remove at least one match\n", 45);
        return (1);
    }
    if (get_number_matches(map, line) == 1)
        return (1);
}