/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_less.c
*/

#include "rpg.h"

int create_sprite_button_less_on(smenu_t *sm)
{
    char *path_to_button = "assets/buttons/less_on.png";

    sm->less_on.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!sm->less_on.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->less_on.boulean_button = true;
    sm->less_on.sprite = sfSprite_create();
    sfSprite_setTexture(sm->less_on.sprite, sm->less_on.texture, sfTrue);
    sm->less_on.pos.x = 600;
    sm->less_on.pos.y = 380;
    sfSprite_setPosition(sm->less_on.sprite, sm->less_on.pos);
    sm->less_on.rect.top = 0;
    sm->less_on.rect.left = 0;
    sm->less_on.rect.width = 240;
    sm->less_on.rect.height = 116;
    return (0);
}

int create_sprite_less_off(smenu_t *sm)
{
    char *path_to_button = "assets/buttons/less_off.png";

    sm->less_off.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!sm->less_off.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->less_off.boulean_button = false;
    sm->less_off.sprite = sfSprite_create();
    sfSprite_setTexture(sm->less_off.sprite, sm->less_off.texture, sfTrue);
    sm->less_off.pos.x = 580;
    sm->less_off.pos.y = 370;
    sfSprite_setPosition(sm->less_off.sprite, sm->less_off.pos);
    sm->less_off.rect.top = 0;
    sm->less_off.rect.left = 0;
    sm->less_off.rect.width = 240;
    sm->less_off.rect.height = 116;
    return (0);
}

void update_button_less(smenu_t *sm, rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(sm->win);
    sfFloatRect less_rect = sfSprite_getGlobalBounds(sm->less_on.sprite);

    if (sfFloatRect_contains(&less_rect, (float)mp.x, (float)mp.y)) {
        sm->less_off.boulean_button = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft) && rpg->volume >= 5)
            rpg->volume -= 5;
    } else
        sm->less_off.boulean_button = 0;
}