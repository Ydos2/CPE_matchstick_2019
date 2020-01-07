/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include "matchstick.h"

int main (int argc, char **argv)
{
    if (argc > 3)
        return (84);
    if (matchstick(argc, argv) == 84)
        return (84);
    return (0);
}