/*
** EPITECH PROJECT, 2019
** menu_principal
** File description:
** button_how_to_play.c
*/

#include "rpg.h"

int create_sprite_button_htp_on(smenu_t *sm)
{
    sm->htp_on.texture = sfTexture_createFromFile(\
    "assets/buttons/how_to_play_on.png", NULL);
    if (!sm->htp_on.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->htp_on.sprite = sfSprite_create();
    sfSprite_setTexture(sm->htp_on.sprite, \
    sm->htp_on.texture, sfTrue);
    sm->htp_on.pos.x = 850;
    sm->htp_on.pos.y = 650;
    sfSprite_setPosition(sm->htp_on.sprite, \
    sm->htp_on.pos);
    sm->htp_on.rect.top = 0;
    sm->htp_on.rect.left = 0;
    sm->htp_on.rect.width = 240;
    sm->htp_on.rect.height = 116;
    return (0);
}

int create_sprite_htp_off(smenu_t *sm)
{
    sm->htp_off.texture = sfTexture_createFromFile(\
    "assets/buttons/how_to_play_off.png", NULL);
    if (!sm->htp_off.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->htp_off.sprite = sfSprite_create();
    sfSprite_setTexture(sm->htp_off.sprite, \
    sm->htp_off.texture, sfTrue);
    sm->htp_off.pos.x = 830;
    sm->htp_off.pos.y = 640;
    sfSprite_setPosition(sm->htp_off.sprite, \
    sm->htp_off.pos);
    sm->htp_off.rect.top = 0;
    sm->htp_off.rect.left = 0;
    sm->htp_off.rect.width = 240;
    sm->htp_off.rect.height = 116;
    return (0);
}

void init_button_how_to_play(smenu_t *sm)
{
    if (sfMouse_getPositionRenderWindow(sm->win).x >= sm->htp_on.pos.x && \
    sfMouse_getPositionRenderWindow(sm->win).x <= sm->htp_on.pos.x + 240 &&\
    sfMouse_getPositionRenderWindow(sm->win).y >= sm->htp_on.pos.y && \
    sfMouse_getPositionRenderWindow(sm->win).y <= sm->htp_on.pos.y + 116) {
        sm->htp_off.boulen_button = 1;
    }
    else
        sm->htp_off.boulen_button = 0;
}