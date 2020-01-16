/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matchstick
*/

#include "my.h"
#include "matchstick.h"

int matchstick(int argc, char **argv, map_t *map)
{
    char *line = NULL;
    size_t len = 0;
    int set_error = 0;

    for (int quit = 0; quit == 0; map->quit_val = 1) {
        if (set_Line(map, line, len, set_error) == -1) {
            map->quit_val = 0;
            return (0);
        }
        set_error = set_Matches(map, line, len);
        if (set_error == -1) {
            map->quit_val = 0;
            return (0);
        }
        quit = set_update(quit, set_error, map);
    }
    return (0);
}

map_t *initialise_start(map_t *map, char **argv)
{
    map = malloc(sizeof(map_t));
    map->quit_val = 0;
    map->error_matches = 0;
    initialise_var(map, argv);
    initialise_map(map);
    return (map);
}

void initialise_var(map_t *map, char **argv)
{
    map->size = my_atoi(argv[1]);
    map->max_get_stick = my_atoi(argv[2]);
    map->line_select = 0;
    map->matches_select = 0;
    map->y = map->size + 2;
    map->x = map->size + map->size + 1;
    map->map_element = malloc(sizeof(char *) * (map->y + 1));
    map->tab = malloc(sizeof(char) * (map->y + 1));
    for (int y = 0; y != map->y; y++) {
        map->map_element[y] = malloc(sizeof(char) * (map->x + 1));
        map->map_element[y][map->x] = '\0';
    }
    map->map_element[map->y+1] = NULL;
}

void initialise_change_player(map_t *map)
{
    int actu_nbr = 0;
    int j = map->tab[map->line_select];
    int z = 0;

    for (z = 0; map->map_element[map->line_select][z] != '|'; z++);
    actu_nbr = map->tab[map->line_select] - map->matches_select;
    if (actu_nbr >= 0)
        for (int i = actu_nbr; i != j; i++)
            set_change_player(map, z);
}

void set_change_player(map_t *map, int z)
{
    int a = 0;

    for (a = z; map->map_element[map->line_select][a] != ' '; a++)
        if (map->map_element[map->line_select][a] == '*')
            break;
    map->map_element[map->line_select][a-1] = ' ';
    map->tab[map->line_select]--;
}