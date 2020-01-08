/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matchstick
*/

#include "my.h"
#include "matchstick.h"

int matchstick(int argc, char **argv)
{
    map_t *map = NULL;
    int quit = 0;
    int action = 1;
    int argc_base = argc;
    char *line = NULL;
    size_t len = 0;

    map = malloc(sizeof(map_t));
    initialise_var(map, argv);
    initialise_map(map);
    print_updated_board_game(map);
    write(1, "Your turn:\nLine: ", 17);
    while (quit == 0) {
        getline(&line, &len, stdin);
        action = set_action(map, action, line);
    }
    return (0);
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

int set_action(map_t *map, int action, char *line)
{
    if (action == 0)
        action = set_Line(map, line);
    else if (action == 1)
        action = set_Matches(map, line);
    return (action);
}

void initialise_change_player(map_t *map)
{
    int actu_nbr = 0;
    int j = map->tab[map->line_select];
    int z = 0;
    int a = 0;

    for (z = 0; map->map_element[map->line_select][z] != '|'; z++);
    actu_nbr = map->tab[map->line_select] - map->matches_select;
    if (actu_nbr >= 0) {
        for (int i = actu_nbr; i != j; i++) {
            for (a = z; map->map_element[map->line_select][a] != ' '; a++);
            map->map_element[map->line_select][a-1] = ' ';
            map->tab[map->line_select]--;
        }
    }
}