/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_inventory.c
*/

#include "rpg.h"

void draw_boots_inventory(rpg_t *rpg)
{
    if (rpg->boots == 1) {
        rpg->boots_1.pos.x = 920;
        rpg->boots_1.pos.y = 905;
        sfSprite_setPosition(rpg->boots_1.sprite, rpg->boots_1.pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->boots_1.sprite, NULL);
    } else if (rpg->boots == 2) {
        rpg->boots_2.pos.x = 920;
        rpg->boots_2.pos.y = 905;
        sfSprite_setPosition(rpg->boots_2.sprite, rpg->boots_2.pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->boots_2.sprite, NULL);
    } else if (rpg->boots == 3) {
        rpg->boots_3.pos.x = 920;
        rpg->boots_3.pos.y = 905;
        sfSprite_setPosition(rpg->boots_3.sprite, rpg->boots_3.pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->boots_3.sprite, NULL);
    }
}

void draw_shield_inventory(rpg_t *rpg)
{
    if (rpg->shield == 1) {
        rpg->shield_1.pos.x = 1045;
        rpg->shield_1.pos.y = 905;
        sfSprite_setPosition(rpg->shield_1.sprite, rpg->shield_1.pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->shield_1.sprite, NULL);
    } else if (rpg->shield == 2) {
        rpg->shield_2.pos.x = 1045;
        rpg->shield_2.pos.y = 905;
        sfSprite_setPosition(rpg->shield_2.sprite, rpg->shield_2.pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->shield_2.sprite, NULL);
    } else if (rpg->shield == 3) {
        rpg->shield_3.pos.x = 1045;
        rpg->shield_3.pos.y = 905;
        sfSprite_setPosition(rpg->shield_3.sprite, rpg->shield_3.pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->shield_3.sprite, NULL);
    }
}

void draw_inventory_two(rpg_t *rpg)
{
    if (rpg->potion == 3) {
        rpg->potion_yellow.pos.x = 795;
        rpg->potion_yellow.pos.y = 900;
        sfSprite_setPosition(rpg->potion_yellow.sprite, rpg->potion_yellow.pos\
);
        sfRenderWindow_drawSprite(rpg->window, rpg->potion_yellow.sprite, NULL\
);
    }
}

void draw_inventory(rpg_t *rpg)
{
    rpg->inv.pos.x = 700;
    rpg->inv.pos.y = 800;
    sfSprite_setPosition(rpg->inv.sprite, rpg->inv.pos);
    sfRenderWindow_drawSprite(rpg->window, rpg->inv.sprite, NULL);
    if (rpg->potion == 1) {
        rpg->potion_red.pos.x = 795;
        rpg->potion_red.pos.y = 900;
        sfSprite_setPosition(rpg->potion_red.sprite, rpg->potion_red.pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->potion_red.sprite, NULL);
    } else if (rpg->potion == 2) {
        rpg->potion_blue.pos.x = 795;
        rpg->potion_blue.pos.y = 900;
        sfSprite_setPosition(rpg->potion_blue.sprite, rpg->potion_blue.pos);
        sfRenderWindow_drawSprite(rpg->window, rpg->potion_blue.sprite, NULL);
    }
    draw_inventory_two(rpg);
}
