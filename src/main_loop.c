/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** open_window.c
*/

#include "rpg.h"

static void (*mv_fct[5])(rpg_t *) = {
    &move_player_up,
    &move_player_down,
    &move_player_left,
    &move_player_right,
    &stay_still,
};

static void (*scenes[2])(rpg_t *) = {
    &menu_loop,
    &game_loop,
};

void game_loop(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->window.window, rpg->event)) {
        open_close_events(rpg->event, rpg->window.window);
        set_movement(rpg);
    }
    for (int i = 0; i < 5; i++) {
        if (rpg->mv[i])
            mv_fct[i](rpg);
    }
    sfSprite_setPosition(rpg->player.sprite, rpg->player.pos);
    display(rpg);
}

void main_loop(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->window.window)) {
        if (rpg->smenu->bool) {
            menu_loop(rpg);
            continue;
        }
        game_loop(rpg);
    }
    sfRenderWindow_destroy(rpg->window.window);
}