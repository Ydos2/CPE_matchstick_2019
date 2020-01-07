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

int set_Line(map_t *map, char *line, int action)
{
    map->line_select = my_atoi(line);
    if (map->y < map->line_select) {
        write(1, "Error: This matches is empty.\n", 30);
        write(1, "Matches: ", 9);
        return (0);
    }
    print_updated_board_game(map);
    write(1, "Your turn:\nLine: ", 17);
    return (1);
}

int set_Matches(map_t *map, char *line, int action)
{
    map->matches_select = my_atoi(line);
    if (map->max_get_stick < map->matches_select) {
        write(1, "Error: This line is empty.\n", 27);
        write(1, "Your turn:\nLine: ", 17);
        return (1);
    }
    write(1, "Matches: ", 9);
    return (0);
}