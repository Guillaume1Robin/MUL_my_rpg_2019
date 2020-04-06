/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parallax_menu.c
*/

#include "rpg.h"

sfIntRect move_init(smenu_t *rpg)
{
    rpg->sprite_rect.top = 0;
    rpg->sprite_rect.left = 0;
    rpg->sprite_rect.width = 1920;
    rpg->sprite_rect.height = 1080;
    return rpg->sprite_rect;
}

void create_parallax_1(smenu_t *rpg)
{
    rpg->para1.texture = sfTexture_createFromFile("assets/parallax/1.png", NULL);
    rpg->para1.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->para1.sprite, rpg->para1.texture, sfTrue);
    sfSprite_setPosition(rpg->para1.sprite, rpg->para1.pos);
    rpg->para1.rect = move_init(rpg);
}

void create_parallax_2(smenu_t *rpg)
{
    rpg->para2.texture = sfTexture_createFromFile("assets/parallax/2eme.png", NULL);
    rpg->para2.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->para2.sprite, rpg->para2.texture, sfTrue);
    sfSprite_setPosition(rpg->para2.sprite, rpg->para2.pos);
    rpg->para2.rect = move_init(rpg);
}

void create_parallax_3(smenu_t *rpg)
{
    rpg->para3.texture = sfTexture_createFromFile("assets/parallax/3eme.png", NULL);
    rpg->para3.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->para3.sprite, rpg->para3.texture, sfTrue);
    sfSprite_setPosition(rpg->para3.sprite, rpg->para3.pos);
    rpg->para3.rect = move_init(rpg);
}

// void create_parallax_4(smenu_t *rpg)
// {
//     rpg->para4.texture = sfTexture_createFromFile("parallax/4.png", NULL);
//     rpg->para4.sprite = sfSprite_create();
//     sfSprite_setTexture(rpg->para4.sprite, rpg->para4.texture, sfTrue);
//     sfSprite_setPosition(rpg->para4.sprite, rpg->para4.pos);
//     rpg->para4.rect = move_init(rpg);
// }
