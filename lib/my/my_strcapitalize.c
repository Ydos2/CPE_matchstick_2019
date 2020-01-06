/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** my_strcapitalize
*/

#include "my.h"

void to_lower(char *c)
{
    if (*c > 64 && *c < 91)
        *c += 32;
}

void to_upper(char *c)
{
    if (*c > 96 && *c < 123)
        *c -= 32;
}

int is_alphanum(char *c)
{
    if (*c > 96 && *c < 123 || *c > 64 && *c < 91 || *c > 47 && *c < 58)
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int length = my_strlen(str);

    to_upper(&str[0]);
    for (int a = 1; a < (length); a++)
        if (!is_alphanum(&str[a-1]))
            to_upper(&str[a]);
        else
            to_lower(&str[a]);
    return (str);
}