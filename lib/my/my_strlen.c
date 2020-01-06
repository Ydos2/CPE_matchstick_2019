/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    char i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}