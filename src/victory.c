/*
** EPITECH PROJECT, 2020
** victory
** File description:
** victory
*/

#include "matchstick.h"

int set_win(map_t *map)
{
    int j = 0;

    for (int i = 0; i != map->y; i++)
        if (map->tab[i] != 0)
            j = 1;
    if (j == 0) {
        print_updated_board_game(map);
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
        print_updated_board_game(map);
        write(1, "I lost... snif... but I'll get you next time!!\n", 47);
        return (1);
    } else
        return (0);
}

void set_end(map_t *map)
{
    my_free_array(map->map_element);
    free(map->tab);
}

void my_free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}