/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main_clock.c
*/

#include "rpg.h"

void clock_move_rect_player(rpg_t *rpg)
{
    sfTime t = sfClock_getElapsedTime(rpg->player->clock);
    float seconds = 0;

    seconds = sfTime_asSeconds(t);
    if (seconds > 0.18) {
        move_hrect(&rpg->player->rect, 32, 64);
        sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
        sfClock_restart(rpg->player->clock);
    }
}