/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** my_strstr
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int str_length = my_strlen(str);
    int to_find_length = my_strlen(to_find);
    int j = 0;

    for (int a = 0; a <= (to_find_length - str_length); j = 0, a++) {
        while ((j < str_length) && (str[j] == to_find[j+a]))
            j++;
        if (j == str_length && str_length != 0)
            return (&str[a]);
    }
    return (0);
}