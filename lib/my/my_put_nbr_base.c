/*
** EPITECH PROJECT, 2019
** my_put_nbr_base
** File description:
** my_put_nbr_base
*/

#include "my.h"

int my_put_nbr_base(int nbr, char *base)
{
    int diviseur = 0;
    int result = 0;
    int t_base = 0;

    t_base = my_strlen(base);
    if (nbr < 0) {
        my_putchar('-');
        nbr = -(nbr);
    }
    diviseur = 1;
    while ((nbr / diviseur) >= t_base)
        diviseur = diviseur * t_base;
    while (diviseur > 0) {
        result = (nbr / diviseur) % t_base;
        my_putchar(base[result]);
        diviseur = diviseur / t_base;
    }
}