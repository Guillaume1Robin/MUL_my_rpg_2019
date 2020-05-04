/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_plus.c
*/

#include "rpg.h"

int create_sprite_button_plus_on(smenu_t *sm)
{
    char *path_to_button = "assets/buttons/plus_on.png";

    sm->plus_on.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!sm->plus_on.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->plus_on.boulean_button = true;
    sm->plus_on.sprite = sfSprite_create();
    sfSprite_setTexture(sm->plus_on.sprite, sm->plus_on.texture, sfTrue);
    sm->plus_on.pos.x = 900;
    sm->plus_on.pos.y = 380;
    sfSprite_setPosition(sm->plus_on.sprite, sm->plus_on.pos);
    sm->plus_on.rect.top = 0;
    sm->plus_on.rect.left = 0;
    sm->plus_on.rect.width = 240;
    sm->plus_on.rect.height = 116;
    return (0);
}

int create_sprite_plus_off(smenu_t *sm)
{
    char *path_to_button = "assets/buttons/plus_off.png";

    sm->plus_off.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!sm->plus_off.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->plus_off.boulean_button = false;
    sm->plus_off.sprite = sfSprite_create();
    sfSprite_setTexture(sm->plus_off.sprite, sm->plus_off.texture, sfTrue);
    sm->plus_off.pos.x = 880;
    sm->plus_off.pos.y = 370;
    sfSprite_setPosition(sm->plus_off.sprite, sm->plus_off.pos);
    sm->plus_off.rect.top = 0;
    sm->plus_off.rect.left = 0;
    sm->plus_off.rect.width = 240;
    sm->plus_off.rect.height = 116;
    return (0);
}

void update_button_plus(smenu_t *sm, rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(sm->win);
    sfFloatRect plus_rect = sfSprite_getGlobalBounds(sm->plus_on.sprite);

    if (sfFloatRect_contains(&plus_rect, (float)mp.x, (float)mp.y)) {
        sm->plus_off.boulean_button = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft) && rpg->volume <= 90)
            rpg->volume += 5;
    } else
        sm->plus_off.boulean_button = 0;
}
