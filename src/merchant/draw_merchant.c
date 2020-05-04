/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_merchant.c
*/

#include "rpg.h"

void draw_merchant(rpg_t *rpg)
{
    draw_informations(rpg);
    rpg->merchant.pos.x = 1180;
    rpg->merchant.pos.y = 170;
    sfSprite_setPosition(rpg->merchant.sprite, rpg->merchant.pos);
    sfRenderWindow_drawSprite(rpg->window, rpg->merchant.sprite, NULL);
    rpg->potion_red.pos.x = 1249;
    rpg->potion_red.pos.y = 250;
    sfSprite_setPosition(rpg->potion_red.sprite, rpg->potion_red.pos);
    if (rpg->potion_red.boulean == 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->potion_red.sprite, NULL);
    rpg->potion_blue.pos.x = 1380;
    rpg->potion_blue.pos.y = 250;
    sfSprite_setPosition(rpg->potion_blue.sprite, rpg->potion_blue.pos);
    if (rpg->potion_blue.boulean == 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->potion_blue.sprite, NULL);
    rpg->potion_yellow.pos.x = 1506;
    rpg->potion_yellow.pos.y = 250;
    sfSprite_setPosition(rpg->potion_yellow.sprite, rpg->potion_yellow.pos);
    if (rpg->potion_yellow.boulean == 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->potion_yellow.sprite, NULL);
}

void draw_boots(rpg_t *rpg)
{
    rpg->boots_1.pos.x = 1626;
    rpg->boots_1.pos.y = 250;
    sfSprite_setPosition(rpg->boots_1.sprite, rpg->boots_1.pos);
    if (rpg->boots_1.boulean == 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->boots_1.sprite, NULL);

    rpg->boots_2.pos.x = 1746;
    rpg->boots_2.pos.y = 250;
    sfSprite_setPosition(rpg->boots_2.sprite, rpg->boots_2.pos);
    if (rpg->boots_2.boulean == 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->boots_2.sprite, NULL);

    rpg->boots_3.pos.x = 1237;
    rpg->boots_3.pos.y = 376;
    sfSprite_setPosition(rpg->boots_3.sprite, rpg->boots_3.pos);
    if (rpg->boots_3.boulean == 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->boots_3.sprite, NULL);
}

void draw_shield(rpg_t *rpg)
{
    rpg->shield_1.pos.x = 1370;
    rpg->shield_1.pos.y = 376;
    sfSprite_setPosition(rpg->shield_1.sprite, rpg->shield_1.pos);
    if (rpg->shield_1.boulean == 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->shield_1.sprite, NULL);

    rpg->shield_2.pos.x = 1500;
    rpg->shield_2.pos.y = 376;
    sfSprite_setPosition(rpg->shield_2.sprite, rpg->shield_2.pos);
    if (rpg->shield_2.boulean == 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->shield_2.sprite, NULL);

    rpg->shield_3.pos.x = 1626;
    rpg->shield_3.pos.y = 376;
    sfSprite_setPosition(rpg->shield_3.sprite, rpg->shield_3.pos);
    if (rpg->shield_3.boulean == 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->shield_3.sprite, NULL);
}

void draw_all_map(rpg_t *rpg)
{
    if (rpg->lvl == 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->npc.sprite, NULL);
    draw_stat(rpg);
    draw_merchant(rpg);
    draw_boots(rpg);
    draw_shield(rpg);
}