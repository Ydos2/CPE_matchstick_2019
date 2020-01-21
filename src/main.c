/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "matchstick.h"

int main(int argc, char **argv)
{
    map_t *map = NULL;

    if (argc != 3)
        return (84);
    if (my_atoi(argv[1]) > 99)
        return (84);
    if (get_first_error(argv[1]) == 1)
        return (84);
    if (get_first_error(argv[2]) == 1)
        return (84);
    map = initialise_start(map, argv);
    if (my_matchstick(argc, argv, map) == 84)
        return (84);
    set_end(map);
    return (map->quit_val);
}