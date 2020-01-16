/*
** EPITECH PROJECT, 2020
** update_game
** File description:
** update_game
*/

#include "my.h"
#include "matchstick.h"

int set_update(int quit, int set_error, map_t *map)
{
    quit = set_win(map);
    if (quit == 2) {
        map->quit_val = 2;
        return (0);
    }
    if (set_error == 0)
        initialise_AI(map);
    quit = set_lose(map);
    return (quit);
}