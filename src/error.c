/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include "matchstick.h"

int get_number_matches(map_t *map, char *line)
{
    int nbr_alpha = 0;

    for (int i = 0; line[i+1] != '\0'; i++)
        if (line[i] < 48 || line[i] > 57) {
            nbr_alpha = 1;
            break;
        }
    if (nbr_alpha == 1 || line[0] == '-' || line[0] == '0') {
        return (1);
    }
    return (0);
}

int get_first_error(char *line)
{
    int nbr_alpha = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] < 48 || line[i] > 57) {
            nbr_alpha = 1;
            break;
        }
    if (nbr_alpha == 1 || line[0] == '-' || line[0] == '0') {
        return (1);
    }
    return (0);
}