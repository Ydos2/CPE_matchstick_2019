/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** my_str_isnum
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (!(str[i] > 47 && str[i] < 58))
            return (1);
    return (0);
}