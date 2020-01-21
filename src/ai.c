/*
** EPITECH PROJECT, 2020
** ai
** File description:
** ai
*/

#include "matchstick.h"

int rand_a_b(int a, int b)
{
    return rand()%(b-a) +a;
}

void initialise_AI(map_t *map)
{
    int nbr_al_line = 0;

    srand(time(NULL));
    while (1) {
        nbr_al_line = rand_a_b(0, map->max_get_stick+1);
        if (map->tab[nbr_al_line] != 0)
            break;
    }
    map->line_select = nbr_al_line;
    set_ai_order(map);
    set_AI(map);
}

void set_ai_order(map_t *map)
{
    int nbr = 0;

    for (int i = 0; i != map->y; i++)
        if (map->tab[i] != 0)
            nbr++;
    if (nbr > 1)
        if (map->tab[map->line_select] >= map->max_get_stick)
            map->matches_select = map->max_get_stick;
        else
            map->matches_select = map->tab[map->line_select];
    else
        if (map->tab[map->line_select] == 1)
            map->matches_select = 1;
        else
            map->matches_select = map->tab[map->line_select] - 1;
}

void set_AI(map_t *map)
{
    print_updated_board_game(map);
    write(1, "\n", 1);
    initialise_change_player(map);
    write(1, "AI's turn...\n", 13);
    write(1, "AI removed ", 11);
    my_put_nbrr(map->matches_select);
    write(1, " match(es) from line ", 21);
    my_put_nbrr(map->line_select);
    write(1, "\n", 1);
}