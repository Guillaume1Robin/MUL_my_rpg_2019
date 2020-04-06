/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main_clock.c
*/

#include "rpg.h"

void clock_display(rpg_t *rpg)
{
    float seconds = 0;

    rpg->clock_display.time = sfClock_getElapsedTime(rpg->clock_display.clock);
    seconds = rpg->clock_display.time.microseconds / 10000;
    if (seconds > 1) {
        display(rpg);
        sfClock_restart(rpg->clock_display.clock);
    }
}

void clock_player(rpg_t *rpg)
{
    float seconds = 0;

    rpg->clock_player.time = sfClock_getElapsedTime(rpg->clock_player.clock);
    seconds = rpg->clock_player.time.microseconds / 10000;
    if (seconds > 1) {
        move_player(rpg);
        sfClock_restart(rpg->clock_player.clock);
    }
}

void clock_move_rect_player(rpg_t *rpg)
{
    float seconds = 0;

    rpg->clock_move_rect_player.time = sfClock_getElapsedTime(rpg->clock_move_rect_player.clock);
    seconds = rpg->clock_move_rect_player.time.microseconds / 100000;
    if (seconds > 1) {
        sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
        sfClock_restart(rpg->clock_move_rect_player.clock);
    }
}