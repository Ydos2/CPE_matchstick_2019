/*
** EPITECH PROJECT, 2020
** victory
** File description:
** victory
*/

#include "my.h"
#include "matchstick.h"

int set_win(map_t *map)
{
    int j = 0;

    for (int i = 0; i != map->y; i++)
        if (map->tab[i] != 0)
            j = 1;
    if (j == 0) {
        write(1, "You lost, too bad...\n", 22);
        return (2);
    } else
        return (0);
}

int set_lose(map_t *map)
{
    int j = 0;

    for (int i = 0; i != map->y; i++)
        if (map->tab[i] != 0)
            j = 1;
    if (j == 0) {
        write(1, "I lost... snif... but I'll get you next time!!\n", 47);
        return (1);
    } else
        return (0);
}