/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_player.c
*/

#include "rpg.h"

void stay_still(rpg_t *rpg)
{
    rpg->player->rect.left = 0;
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
}

void move_player_down(rpg_t *rpg)
{
    int y = (rpg->player->pos.y + rpg->player->speed + 32) / 32;
    int x = (rpg->player->pos.x) / 32;
    level_t *curr_lvl = rpg->levels[rpg->lvl];

    rpg->player->rect.top = 0;
    if (rpg->player->pos.y <= HEIGHT && !curr_lvl->collisions[y][x]) {
        rpg->player->pos.y += rpg->player->speed;
        rpg->player->rect.top = 0;
        clock_move_rect_player(rpg);
    }
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
}

void move_player_up(rpg_t *rpg)
{
    int y = (rpg->player->pos.y - rpg->player->speed - 10) / 32;
    int x = (rpg->player->pos.x) / 32;
    level_t *curr_lvl = rpg->levels[rpg->lvl];

    rpg->player->rect.top = 32;
    if (rpg->player->pos.y >= 0 && !curr_lvl->collisions[y][x]) {
        rpg->player->pos.y -= rpg->player->speed;
        clock_move_rect_player(rpg);
    }
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
}

void move_player_left(rpg_t *rpg)
{
    int y = (rpg->player->pos.y + 30) / 32;
    int x = (rpg->player->pos.x - rpg->player->speed - 28) / 32;
    level_t *curr_lvl = rpg->levels[rpg->lvl];

    rpg->player->rect.top = 64;
    if (rpg->player->pos.x >= 0 && !curr_lvl->collisions[y][x]) {
        rpg->player->pos.x -= rpg->player->speed;
        clock_move_rect_player(rpg);
    }
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
}

void move_player_right(rpg_t *rpg)
{
    int y = (rpg->player->pos.y + 30) / 32;
    int x = (rpg->player->pos.x + rpg->player->speed + 28) / 32;
    level_t *curr_lvl = rpg->levels[rpg->lvl];

    rpg->player->rect.top = 96;
    if (rpg->player->pos.x <= WIDTH && !curr_lvl->collisions[y][x]) {
        rpg->player->pos.x += rpg->player->speed;
        clock_move_rect_player(rpg);
    }
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
}