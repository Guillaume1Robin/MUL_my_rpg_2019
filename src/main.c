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

<<<<<<< HEAD
    rpg->map.map = collision_parser("map_txt/map1");
    if (!initialise_value_struct(rpg))
    create(rpg);
    open_window(rpg);
    free(rpg);
=======
    if (!initialise_value_struct(rpg)) {
        create(rpg);
        main_loop(rpg);
        free(rpg);
        return (0);
    }
>>>>>>> master
}
