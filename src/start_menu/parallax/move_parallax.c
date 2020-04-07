/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_parallax.c
*/

#include "rpg.h"

void move_hrect(sfIntRect *rectangle, int offset, int max_value)
{
    rectangle->left = rectangle->left + offset;
    if (rectangle->left > max_value)
        rectangle->left = 1920;
}

void move_vrect(sfIntRect *rectangle, int offset, int max_value)
{
    rectangle->top = rectangle->top + offset;
    if (rectangle->top > max_value)
        rectangle->top = 0;
}

void move_parallax(smenu_t *menu)
{
    for (int i = 0; menu->para[i]; i++) {
        if (i == 1)
            move_hrect(&menu->para[i]->rect, 3, 3840);
        else
            move_hrect(&menu->para[i]->rect, 1, 3840);
        sfSprite_setTextureRect(menu->para[i]->sprite, menu->para[i]->rect);
    }
}