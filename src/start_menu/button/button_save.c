/*
** EPITECH PROJECT, 2019
** menu_principal
** File description:
** buton_save.c
*/

#include "rpg.h"

int create_sprite_button_save_on(smenu_t *sm)
{
    sm->save_on.texture = sfTexture_createFromFile("assets/buttons/save_on.png", NULL);
    if (!sm->save_on.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->save_on.sprite = sfSprite_create();
    sfSprite_setTexture(sm->save_on.sprite, sm->save_on.texture, sfTrue);
    sm->save_on.pos.x = 850;
    sm->save_on.pos.y = 500;
    sfSprite_setPosition(sm->save_on.sprite, sm->save_on.pos);
    sm->save_on.rect.top = 0;
    sm->save_on.rect.left = 0;
    sm->save_on.rect.width = 240;
    sm->save_on.rect.height = 116;
    return (0);
}

int create_sprite_save_off(smenu_t *sm)
{
    sm->save_off.texture = sfTexture_createFromFile("assets/buttons/save_off.png", NULL);
    if (!sm->save_off.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->save_off.sprite = sfSprite_create();
    sfSprite_setTexture(sm->save_off.sprite, sm->save_off.texture, sfTrue);
    sm->save_off.pos.x = 830;
    sm->save_off.pos.y = 490;
    sfSprite_setPosition(sm->save_off.sprite, sm->save_off.pos);
    sm->save_off.rect.top = 0;
    sm->save_off.rect.left = 0;
    sm->save_off.rect.width = 240;
    sm->save_off.rect.height = 116;
    return (0);
}

void update_button_save(smenu_t *sm)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(sm->win);
    sfFloatRect save_rect = sfSprite_getGlobalBounds(sm->save_on.sprite);

    if (sfFloatRect_contains(&save_rect, (float)mp.x, (float)mp.y)) {
        sm->save_off.boulen_button = 1;
    } else
        sm->save_off.boulen_button = 0;
}