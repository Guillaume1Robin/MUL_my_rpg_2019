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
    rpg->para1.rect = move_init2(rpg);
}

void create_parallax_2(smenu_t *rpg)
{
    rpg->para2.texture = sfTexture_createFromFile("assets/parallax/2eme.png", NULL);
    rpg->para2.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->para2.sprite, rpg->para2.texture, sfTrue);
    sfSprite_setPosition(rpg->para2.sprite, rpg->para2.pos);
    rpg->para2.rect = move_init2(rpg);
}

void create_parallax_3(smenu_t *rpg)
{
    rpg->para3.texture = sfTexture_createFromFile("assets/parallax/3eme.png", NULL);
    rpg->para3.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->para3.sprite, rpg->para3.texture, sfTrue);
    sfSprite_setPosition(rpg->para3.sprite, rpg->para3.pos);
    rpg->para3.rect = move_init2(rpg);
}

void create_parallax_5(smenu_t *smenu)
{
    smenu->para5.texture = sfTexture_createFromFile("assets/parallax/5.png", NULL);
    smenu->para5.sprite = sfSprite_create();
    sfSprite_setTexture(smenu->para5.sprite, smenu->para5.texture, sfTrue);
    sfSprite_setPosition(smenu->para1.sprite, smenu->para5.pos);
    smenu->para5.rect = move_init2(smenu);
}

// void create_parallax(smenu_t *menu)
// {
//     char *name = NULL;

//     for (int i = 0; i < 5; i++) {
//         name = my_strcat(my_strcat("assets/parallax/", my_itos(i)), ".png");
//         menu->para.texture = sfTexture_createFromFile("assets/parallax/3eme.png", NULL);
//         menu->para.sprite = sfSprite_create();
//         sfSprite_setTexture(menu->para.sprite, menu->para.texture, sfTrue);
//         sfSprite_setPosition(menu->para.sprite, menu->para.pos);
//         menu->para.rect = move_init(menu);
//     }
// }

// void create_parallax_4(smenu_t *rpg)
// {
//     rpg->para4.texture = sfTexture_createFromFile("parallax/4.png", NULL);
//     rpg->para4.sprite = sfSprite_create();
//     sfSprite_setTexture(rpg->para4.sprite, rpg->para4.texture, sfTrue);
//     sfSprite_setPosition(rpg->para4.sprite, rpg->para4.pos);
//     rpg->para4.rect = move_init(rpg);
// }
