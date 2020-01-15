/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include "my.h"
#include "matchstick.h"

int get_Matches_error(map_t *map, char *line, size_t len)
{
    write(1, "Error: you cannot remove more than ", 36);
    my_put_nbrr(map->matches_select);
    write(1, " matches per turn\n", 18);
    return (1);
}

int get_number_matches(map_t *map, char *line)
{
    map->matches_select = my_atoi(line);
    if (map->matches_select < 0) {
        write(1, "Error: invalid input (positive number expected)", 47);
        return (1);
    }
    return (0);
}