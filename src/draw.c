/*
** EPITECH PROJECT, 2020
** draw
** File description:
** draw
*/

#include "my.h"
#include "matchstick.h"

void print_updated_board_game(map_t *map)
{
    for (int y = 0; y != map->y; y++) {
        my_putstr(map->map_element[y]);
        write(1, "\n", 1);
    }
}

void set_Line(map_t *map, char *line, size_t len, int error)
{
    if (error == 0) {
        print_updated_board_game(map);
        write(1, "\nYour turn:\nLine: ", 18);
    } else {
        write(1, "Error: this line is out of range\n", 33);
        exit (0);
    }
    getline(&line, &len, stdin);
    map->line_select = my_atoi(line);
    if (map->y-1 <= map->line_select || map->line_select <= 0)
        set_Line(map, line, len, 1);
}

int set_Matches(map_t *map, char *line, size_t len, int error)
{
    if (error == 0)
        write(1, "Matches: ", 9);
    else {
        write(1, "Error: you cannot remove more than ", 36);
        my_put_nbrr(map->matches_select);
        write(1, " matches per turn\n", 18);
        getline(&line, &len, stdin);
        return (1);
    }
    getline(&line, &len, stdin);
    map->matches_select = my_atoi(line);
    if (map->max_get_stick < map->matches_select)
        set_Matches(map, line, len, 1);
    initialise_change_player(map);
    write(1, "Player removed ", 15);
    my_put_nbrr(map->matches_select);
    write(1, " match(es) from line ", 21);
    my_put_nbrr(map->line_select);
    write(1, "\n", 1);
    return (0);
}

void initialise_AI(map_t *map)
{
    map->line_select = 1;
    map->matches_select = 1;
    for (int i = 1; i != map->y; i++)
        if (map->tab[i] != 0)
            map->line_select = i++;
    set_AI(map);
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