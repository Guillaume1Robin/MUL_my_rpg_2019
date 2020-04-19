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

    rpg->levels = create_game_layout(MAX_LEVEL - 1);
    init_music(rpg);
    if (!initialize_value_struct(rpg)) {
        create(rpg);
        play_music(rpg);
        main_loop(rpg);
        destroy_rpg(rpg);
        free(rpg);
        return (0);
    }
    return (84);
}