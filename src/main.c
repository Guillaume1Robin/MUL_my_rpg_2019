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

    rpg->map.map = collision_parser("map_txt/map5");
    if (!initialise_value_struct(rpg)) {
        create(rpg);
        main_loop(rpg);
        free(rpg);
        return (0);
    }
}
