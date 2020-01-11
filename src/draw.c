/*
** EPITECH PROJECT, 2020
** draw
** File description:
** draw
*/

#include "my.h"
#include "matchstick.h"

void print_updated_board_game(map_t *map)
{
    for (int y = 0; y != map->y; y++) {
        my_putstr(map->map_element[y]);
        write(1, "\n", 1);
    }
}

void set_Line(map_t *map, char *line, size_t len, int error)
{
    if (error == 0) {
        print_updated_board_game(map);
        write(1, "Your turn:\nLine: ", 17);
    } else {
        write(1, "Error: This line is empty.\n", 27);
        write(1, "Your turn:\nLine: ", 17);
    }
    getline(&line, &len, stdin);
    map->line_select = my_atoi(line);
    if (map->y-1 <= map->line_select)
        set_Line(map, line, len, 1);
}

void set_Matches(map_t *map, char *line, size_t len, int error)
{
    if (error == 0)
        write(1, "Matches: ", 9);
    else {
        write(1, "Error: This Matches is empty.\n", 27);
        write(1, "Your turn:\nMatches: ", 17);
    }
    getline(&line, &len, stdin);
    map->matches_select = my_atoi(line);
    if (map->max_get_stick < map->matches_select)
        set_Matches(map, line, len, 1);
    initialise_change_player(map);
}