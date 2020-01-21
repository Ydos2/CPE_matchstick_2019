/*
** EPITECH PROJECT, 2019
** criterion
** File description:
** criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}