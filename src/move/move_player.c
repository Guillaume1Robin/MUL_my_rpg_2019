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
    int y = rpg->player.pos.y / 32;
    int x = rpg->player.pos.x / 32;

    rpg->player.rect.top = 0;
    if (rpg->player.pos.y <= HEIGHT && rpg->map.map[y + 1][x] != 2) {
        rpg->player.pos.y += 1;
        rpg->player.rect.top = 0;
        clock_move_rect_player(rpg);
    }
    sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
}

void move_player_up(rpg_t *rpg)
{
    int y = rpg->player.pos.y / 32;
    int x = rpg->player.pos.x / 32;

    rpg->player.rect.top = 32;
    if (rpg->player.pos.y >= 0 && rpg->map.map[y - 1][x] != 2) {
        rpg->player.pos.y -= 1;
        clock_move_rect_player(rpg);
    }
    sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
}

void move_player_left(rpg_t *rpg)
{
    int y = rpg->player.pos.y / 32;
    int x = rpg->player.pos.x / 32;

    rpg->player.rect.top = 64;
    if (rpg->player.pos.x >= 0 && rpg->map.map[y][x - 1] != 2) {
        rpg->player.pos.x -= 1;
        clock_move_rect_player(rpg);
    }
    sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
}

void move_player_right(rpg_t *rpg)
{
    int y = rpg->player.pos.y / 32;
    int x = rpg->player.pos.x / 32;

    rpg->player.rect.top = 96;
    if (rpg->player.pos.x <= WIDTH && rpg->map.map[y][x + 1] != 2) {
        rpg->player.pos.x += 1;
        clock_move_rect_player(rpg);
    }
    sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
}