/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    char i = 0;

    for (; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}