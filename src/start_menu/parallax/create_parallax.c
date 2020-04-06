/*
** EPITECH PROJECT, 2019
** menu_principal
** File description:
** create_parallax.c
*/

#include "rpg.h"

// void create_parallax(smenu_t *smenu)
// {
//     create_parallax_1(smenu);
//     create_parallax_2(smenu);
//     create_parallax_3(smenu);
//     // create_parallax_4(smenu);
//     create_parallax_5(smenu);
//     create_sky(smenu);
// }

void create_parallax(smenu_t *menu)
{
    char *name = NULL;

    menu->para = malloc(sizeof(menu_t *) * (6));
    menu->para[5] = NULL;
    for (int i = 0; i < 5; i++) {
        menu->para[i] = malloc(sizeof(menu_t));
        name = my_strcat(my_strcat("assets/parallax/", my_itos(i)), ".png");
        menu->para[i]->texture = sfTexture_createFromFile(name, NULL);
        menu->para[i]->sprite = sfSprite_create();
        sfSprite_setTexture(menu->para[i]->sprite, menu->para[i]->texture, sfTrue);
        sfSprite_setPosition(menu->para[i]->sprite, menu->para[i]->pos);
        menu->para[i]->rect = init_rect(menu);
    }
}

void create_sky(smenu_t *smenu)
{
    smenu->sky.texture = sfTexture_createFromFile("assets/parallax/0.png", NULL);
    smenu->sky.sprite = sfSprite_create();
    sfSprite_setTexture(smenu->sky.sprite, smenu->sky.texture, sfTrue);
    sfSprite_setPosition(smenu->sky.sprite, smenu->sky.pos);
}

void draw_parallax(smenu_t *menu)
{
    for (int i = 0; menu->para[i]; i++)
        sfRenderWindow_drawSprite(menu->win, menu->para[i]->sprite, NULL);
}

sfIntRect init_rect(smenu_t *smenu)
{
    smenu->sprite_rect.top = 0;
    smenu->sprite_rect.left = 0;
    smenu->sprite_rect.width = WIDTH;
    smenu->sprite_rect.height = HEIGHT;
    return (smenu->sprite_rect);
}

