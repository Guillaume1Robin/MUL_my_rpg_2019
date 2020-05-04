/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_text_box.c
*/

#include "rpg.h"

void draw_text_box(sfRenderWindow *win, text_t text_box)
{
    sfRenderWindow_drawSprite(win, text_box.box_sprite, NULL);
    sfRenderWindow_drawText(win, text_box.stc, NULL);
}