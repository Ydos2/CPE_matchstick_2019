/*
** EPITECH PROJECT, 2020
** tools_functions
** File description:
** tools_functions
*/

#include "my.h"
#include "matchstick.h"

int my_atoi(char *str)
{
    int longueur = my_strlenn(str);
    int result = 0;

    for (int i = 0; i < longueur && longueur < 9; ++i)
        if (str[i] >= '0' && str[i] <= '9') {
            result += str[i] - '0';
            result *= 10;
        }
    return (result /= 10);
}

int my_putstr(char const *str)
{
    char i = 0;

    for (; str[i] != '\0'; i++)
        write(1, &str[i], 1);
    return (0);
}

int my_strlenn(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}