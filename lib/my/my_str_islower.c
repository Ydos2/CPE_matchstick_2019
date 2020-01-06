/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** my_str_islower
*/

#include "my.h"

int my_str_islower(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!(str[i] > 96 && str[i] < 123))
            return (1);
    return (0);
}