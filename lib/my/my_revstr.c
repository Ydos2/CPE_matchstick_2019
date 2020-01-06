/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** my_revstr
*/

#include "my.h"

char my_compt(char *str)
{
    char i;

    for (i = 0; str[i]; ++i);
    return (i);
}

char *my_revstr(char *str)
{
    char save;
    char a;
    char b;

    for (a = my_compt(str) - 1, b = 0; b < a; ++b, --a) {
        save = str[b];
        str[b] = str[a];
        str[a] = save;
    }
    return (str);
}