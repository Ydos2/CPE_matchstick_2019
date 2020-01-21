/*
** EPITECH PROJECT, 2020
** update_game
** File description:
** update_game
*/

#include "matchstick.h"

int set_update(int quit, int set_error, map_t *map)
{
    quit = set_win(map);
    if (quit == 2) {
        map->quit_val = 2;
        return (2);
    }
    if (set_error == 0)
        initialise_AI(map);
    quit = set_lose(map);
    return (quit);
}

void set_update_matches(map_t *map)
{
    initialise_change_player(map);
    write(1, "Player removed ", 15);
    my_put_nbrr(map->matches_select);
    write(1, " match(es) from line ", 21);
    my_put_nbrr(map->line_select);
    write(1, "\n", 1);
}