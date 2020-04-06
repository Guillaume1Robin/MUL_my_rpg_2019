/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_parallax.c
*/

#include "rpg.h"

void move_rect(sfIntRect *rectangle, int offset, int max_value)
{
    rectangle->left = rectangle->left + offset;
    if (rectangle->left > max_value)
        rectangle->left = 0;
}

void move_parallax(smenu_t *rpg)
{
    move_rect(&rpg->para1.rect, 2, 3840);
    sfSprite_setTextureRect(rpg->para1.sprite, rpg->para1.rect);

    move_rect(&rpg->para2.rect, 1, 3840);
    sfSprite_setTextureRect(rpg->para2.sprite, rpg->para2.rect);

    move_rect(&rpg->para3.rect, 1, 3840);
    sfSprite_setTextureRect(rpg->para3.sprite, rpg->para3.rect);

    // move_rect(&rpg->para4.rect, 4, 3840);
    // sfSprite_setTextureRect(rpg->para4.sprite, rpg->para4.rect);

    move_rect(&rpg->para5.rect, 1, 3840);
    sfSprite_setTextureRect(rpg->para5.sprite, rpg->para5.rect);
}