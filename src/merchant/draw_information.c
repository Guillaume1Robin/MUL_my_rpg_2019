/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_information.c
*/

#include "rpg.h"

void draw_information_two(rpg_t *rpg)
{
    if (rpg->check_item == 3) {
        rpg->box_info.pos.x = 1400;
        rpg->box_info.pos.y = 100;
        sfSprite_setPosition(rpg->box_info.box_sprite, rpg->box_info.pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->box_info.box_sprite, NULL);
        sfRenderWindow_drawText(rpg->window, rpg->box_info_15.stc, NULL);
    }
}

void draw_informations(rpg_t *rpg)
{
    if (rpg->check_item == 1) {
        rpg->box_info.pos.x = 1400;
        rpg->box_info.pos.y = 100;
        sfSprite_setPosition(rpg->box_info.box_sprite, rpg->box_info.pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->box_info.box_sprite, NULL);
        sfRenderWindow_drawText(rpg->window, rpg->box_info.stc, NULL);
    }
    if (rpg->check_item == 2) {
        rpg->box_info.pos.x = 1400;
        rpg->box_info.pos.y = 100;
        sfSprite_setPosition(rpg->box_info.box_sprite, rpg->box_info.pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->box_info.box_sprite, NULL);
        sfRenderWindow_drawText(rpg->window, rpg->box_info_10.stc, NULL);
    }
    draw_information_two(rpg);
}