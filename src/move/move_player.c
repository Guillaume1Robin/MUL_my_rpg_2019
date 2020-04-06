/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_player.c
*/

#include "rpg.h"

void move_player_up(rpg_t *rpg)
{
    rpg->player.pos.y -= 3;
    if (rpg->player.rect.left >= 192 - 64)
        rpg->player.rect.left = 0;
    rpg->player.rect.top = 64;
    rpg->player.rect.left += 64;
}

void move_player_left(rpg_t *rpg)
{
    rpg->player.pos.x -= 3;
    if (rpg->player.rect.left >= 192 - 64)
        rpg->player.rect.left = 0;
    rpg->player.rect.top = 128;
    rpg->player.rect.left += 64;
}

void move_player_right(rpg_t *rpg)
{
    rpg->player.pos.x += 3;
    if (rpg->player.rect.left >= 192 - 64)
        rpg->player.rect.left = 0;
    rpg->player.rect.top = 192;
    rpg->player.rect.left += 64;
}

void move_player_down(rpg_t *rpg)
{
    rpg->player.pos.y += 3;
    if (rpg->player.rect.left >= 192 - 64)
        rpg->player.rect.left = 0;
    rpg->player.rect.top = 0;
    rpg->player.rect.left += 64;
}

void move_player(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        if (rpg->player.pos.y >= 0)
            move_player_up(rpg);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        if (rpg->player.pos.x >= 0)
            move_player_left(rpg);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        if (rpg->player.pos.y <= HEIGHT)
            move_player_down(rpg);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        if (rpg->player.pos.x <= WIDTH)
            move_player_right(rpg);
    sfSprite_setPosition(rpg->player.sprite, rpg->player.pos);
}