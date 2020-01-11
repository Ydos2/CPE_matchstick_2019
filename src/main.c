/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include "matchstick.h"

int main (int argc, char **argv)
{
    map_t *map = NULL;

    if (argc > 3)
        return (84);
    map = initialise_start(map, argv);
    if (matchstick(argc, argv, map) == 84)
        return (84);
    return (map->quit_val);
}