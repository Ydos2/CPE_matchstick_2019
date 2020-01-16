/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include "my.h"
#include "matchstick.h"

int get_number_matches(map_t *map, char *line)
{
    map->matches_select = my_atoi(line);
    if (map->matches_select < 0) {
        write(1, "Error: invalid input (positive number expected)", 47);
        return (1);
    }
    return (0);
}