/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include "matchstick.h"

void initialise_map(map_t *map)
{
    map->stick_max = (map->x -1) / 2;
    map->stick_min = map->stick_max;

    for (int y = 0; y != map->y; y++) {
        for (int x = 0; x != map->x; x++)
            set_map(map, x, y);
        if (y != 0) {
            map->stick_min = map->stick_min - 1;
            map->stick_max = map->stick_max + 1;
        }
    }
    for (int xx = 0; map->map_element[0][xx] != '\0'; xx++)
        map->map_element[0][xx] = '*';
}

void set_map(map_t *map, int x, int y)
{
    if (y == 0 || y == map->y-1 || x == 0 || x == map->x-1)
        map->map_element[y][x] = '*';
    else if (x >= map->stick_min && x <= map->stick_max) {
        map->map_element[y][x] = '|';
        map->tab[y] += 1;
    } else
        map->map_element[y][x] = ' ';
}