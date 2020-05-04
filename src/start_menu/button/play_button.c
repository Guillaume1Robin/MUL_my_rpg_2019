/*
** EPITECH PROJECT, 2019
** menu_principal
** File description:
** create_button.c
*/

#include "rpg.h"

int create_sprite_button_play_on(smenu_t *sm)
{
    char *path_to_button = "assets/buttons/play_on.png";

    sm->play_on.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!sm->play_on.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->play_on.sprite = sfSprite_create();
    sfSprite_setTexture(sm->play_on.sprite, sm->play_on.texture, sfTrue);
    sm->play_on.pos.x = 850;
    sm->play_on.pos.y = 350;
    sfSprite_setPosition(sm->play_on.sprite, sm->play_on.pos);
    sm->play_on.rect.top = 0;
    sm->play_on.rect.left = 0;
    sm->play_on.rect.width = 240;
    sm->play_on.rect.height = 116;
    return (0);
}

int create_sprite_play_off(smenu_t *sm)
{
    char *path_to_button = "assets/buttons/play_off.png";

    sm->play_off.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!sm->play_off.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->play_off.sprite = sfSprite_create();
    sfSprite_setTexture(sm->play_off.sprite, sm->play_off.texture, sfTrue);
    sm->play_off.pos.x = 830;
    sm->play_off.pos.y = 340;
    sfSprite_setPosition(sm->play_off.sprite, sm->play_off.pos);
    sm->play_off.rect.top = 0;
    sm->play_off.rect.left = 0;
    sm->play_off.rect.width = 240;
    sm->play_off.rect.height = 116;
    return (0);
}

void update_button_play(smenu_t *sm, rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(sm->win);
    sfFloatRect play_rect = sfSprite_getGlobalBounds(sm->play_on.sprite);

    if (sfFloatRect_contains(&play_rect, (float)mp.x, (float)mp.y)) {
        sm->play_off.boulean_button = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            rpg->prev_scene = rpg->scene;
            rpg->scene = GAME;
            rpg->game_clock = sfClock_create();
        }
    } else
        sm->play_off.boulean_button = 0;
}