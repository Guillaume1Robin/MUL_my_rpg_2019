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

    rpg->map.map = collision_parser("map_txt/map1");
    for (int y = 0; rpg->map.map[y]; y++) {
        for (int x = 0; rpg->map.map[y][x] >= 0; x++)
            printf("%d", rpg->map.map[y][x]);
        printf("\n");
    }
    if (!initialise_value_struct(rpg)) {
        create(rpg);
        play_music(rpg);
        main_loop(rpg);
        free(rpg);
        return (0);
    }
}
