/*
** EPITECH PROJECT, 2019
** my_str_isakpha
** File description:
** my_str_isalpha
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i]; ++i)
        if (!(str[i] >= 'a' && str[i] <= 'z')
        || !(str[i] >= 'A' && str[i] <= 'Z'))
            return (1);
    return (0);
}