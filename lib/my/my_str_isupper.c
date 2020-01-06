/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** my_str_isupper
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!(str[i] > 64 && str[i] < 91))
            return (1);
    return (0);
}