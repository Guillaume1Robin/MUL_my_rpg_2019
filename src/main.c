/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "rpg.h"

int main(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (!initialise_value_struct(rpg))
    create(rpg);
    open_window(rpg);
    free(rpg);
}
