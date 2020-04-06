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

void move_parallax(smenu_t *menu)
{
    for (int i = 0; menu->para[i]; i++) {
        move_rect(&menu->para[i]->rect, i + 1, 3840);
        sfSprite_setTextureRect(menu->para[i]->sprite, menu->para[i]->rect);
    }
}