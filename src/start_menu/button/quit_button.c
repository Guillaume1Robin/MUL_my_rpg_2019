/*
** EPITECH PROJECT, 2019
** menu_principal
** File description:
** button_quit.c
*/

#include "rpg.h"

int create_sprite_button_quit_on(smenu_t *sm)
{
    char *path_to_button = "assets/buttons/quit_on.png";

    sm->quit_on.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!sm->quit_on.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->quit_on.sprite = sfSprite_create();
    sfSprite_setTexture(sm->quit_on.sprite, sm->quit_on.texture, sfTrue);
    sm->quit_on.pos.x = 850;
    sm->quit_on.pos.y = 650;
    sfSprite_setPosition(sm->quit_on.sprite, sm->quit_on.pos);
    sm->quit_on.rect.top = 0;
    sm->quit_on.rect.left = 0;
    sm->quit_on.rect.width = 240;
    sm->quit_on.rect.height = 116;
    return (0);
}

int create_sprite_quit_off(smenu_t *sm)
{
    char *path_to_button = "assets/buttons/quit_off.png";

    sm->quit_off.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!sm->quit_off.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->quit_off.sprite = sfSprite_create();
    sfSprite_setTexture(sm->quit_off.sprite, sm->quit_off.texture, sfTrue);
    sm->quit_off.pos.x = 830;
    sm->quit_off.pos.y = 640;
    sfSprite_setPosition(sm->quit_off.sprite, sm->quit_off.pos);
    sm->quit_off.rect.top = 0;
    sm->quit_off.rect.left = 0;
    sm->quit_off.rect.width = 240;
    sm->quit_off.rect.height = 116;
    return (0);
}

void update_button_quit(smenu_t *sm)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(sm->win);
    sfFloatRect quit_rect = sfSprite_getGlobalBounds(sm->quit_on.sprite);

    if (sfFloatRect_contains(&quit_rect, (float)mp.x, (float)mp.y)) {
        sm->quit_off.boulean_button = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRenderWindow_close(sm->win);
            return;
        }
    } else
        sm->quit_off.boulean_button = 0;
}