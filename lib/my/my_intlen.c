/*
** EPITECH PROJECT, 2019
** intlen
** File description:
** intlen
*/

#include "my.h"

int my_intlen(int nb)
{
    float float_int = nb;
    int result;

    for (result = 0; float_int >= 1; float_int /= 10, result++);
    return (result);
}