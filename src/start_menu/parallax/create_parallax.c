/*
** EPITECH PROJECT, 2019
** menu_principal
** File description:
** create_parallax.c
*/

#include "rpg.h"

void create_parallax(smenu_t *sm)
{
    char *name = NULL;

    sm->para = malloc(sizeof(parallax_t *) * (6));
    sm->para[5] = NULL;
    for (int i = 0; i < 5; i++) {
        sm->para[i] = malloc(sizeof(parallax_t));
        name = my_strcat(my_strcat("assets/parallax/", my_itos(i)), ".png");
        sm->para[i]->texture = sfTexture_createFromFile(name, NULL);
        sm->para[i]->sprite = sfSprite_create();
        sfSprite_setTexture(sm->para[i]->sprite, sm->para[i]->texture, sfTrue);
        sfSprite_setPosition(sm->para[i]->sprite, (sfVector2f){0,0});
        sm->para[i]->rect = init_rect(sm);
        free(name);
    }
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
    smenu->sprite_rect.width = 1920;
    smenu->sprite_rect.height = 1080;
    return (smenu->sprite_rect);
}

