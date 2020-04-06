/*
** EPITECH PROJECT, 2019
** menu_principal
** File description:
** create_parallax.c
*/

#include "rpg.h"

void create_parallax(smenu_t *smenu)
{
    create_parallax_1(smenu);
    create_parallax_2(smenu);
    create_parallax_3(smenu);
    // create_parallax_4(smenu);
    create_parallax_5(smenu);
    create_sky(smenu);
}

void create_sky(smenu_t *smenu)
{
    smenu->sky.texture = sfTexture_createFromFile("assets/parallax/sky.png", NULL);
    smenu->sky.sprite = sfSprite_create();
    sfSprite_setTexture(smenu->sky.sprite, smenu->sky.texture, sfTrue);
    sfSprite_setPosition(smenu->sky.sprite, smenu->sky.pos);
}

void draw_parallax(smenu_t *smenu)
{
    // sfRenderWindow_drawSprite(smenu->win, smenu->sky.sprite, NULL);
    sfRenderWindow_drawSprite(smenu->win, smenu->para1.sprite, NULL);
    sfRenderWindow_drawSprite(smenu->win, smenu->para2.sprite, NULL);
    sfRenderWindow_drawSprite(smenu->win, smenu->para3.sprite, NULL);
    // sfRenderWindow_drawSprite(smenu->win, smenu->para4.sprite, NULL);
    sfRenderWindow_drawSprite(smenu->win, smenu->para5.sprite, NULL);
}

sfIntRect move_init2(smenu_t *smenu)
{
    smenu->sprite_rect.top = 0;
    smenu->sprite_rect.left = 0;
    smenu->sprite_rect.width = 1920;
    smenu->sprite_rect.height = 1080;
    return (smenu->sprite_rect);
}

void create_parallax_5(smenu_t *smenu)
{
    smenu->para5.texture = sfTexture_createFromFile("assets/parallax/5.png", NULL);
    smenu->para5.sprite = sfSprite_create();
    sfSprite_setTexture(smenu->para5.sprite, smenu->para5.texture, sfTrue);
    sfSprite_setPosition(smenu->para1.sprite, smenu->para5.pos);
    smenu->para5.rect = move_init2(smenu);
}
