/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_player.c
*/

#include "rpg.h"

void stay_still(rpg_t *rpg)
{
    rpg->player.rect.left = 0;
    sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
}

void move_player_down(rpg_t *rpg)
{
    if (rpg->player.pos.y <= HEIGHT) {
        rpg->player.pos.y += 3;
        rpg->player.rect.top = 0;
        clock_move_rect_player(rpg);
    }
    sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
}

void move_player_up(rpg_t *rpg)
{
    rpg->player.rect.top = 32;
    if (rpg->player.pos.y >= 0) {
        rpg->player.pos.y -= 3;
        clock_move_rect_player(rpg);
    }
    sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
}

void move_player_left(rpg_t *rpg)
{
    rpg->player.rect.top = 64;
    if (rpg->player.pos.x >= 0) {
        rpg->player.pos.x -= 3;
        clock_move_rect_player(rpg);
    }
    sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
}

void move_player_right(rpg_t *rpg)
{
    rpg->player.rect.top = 96;
    if (rpg->player.pos.x <= WIDTH) {
        rpg->player.pos.x += 3;
        clock_move_rect_player(rpg);
    }
    sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
}