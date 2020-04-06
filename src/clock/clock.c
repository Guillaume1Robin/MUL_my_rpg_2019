/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main_clock.c
*/

#include "rpg.h"

void clock_move_rect_player(rpg_t *rpg)
{
    float seconds = 0;

    rpg->clock_move_rect_player.time = \
    sfClock_getElapsedTime(rpg->clock_move_rect_player.clock);
    seconds = sfTime_asSeconds(rpg->clock_move_rect_player.time);
    if (seconds > 0.2) {
        move_hrect(&rpg->player.rect, 32, 64);
        sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
        sfClock_restart(rpg->clock_move_rect_player.clock);
    }
}