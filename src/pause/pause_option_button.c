/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pause_option_button.c
*/

#include "rpg.h"

int create_sprite_option_button_on(smenu_t *sm)
{
    char *path_to_button = "assets/buttons/option_on.png";

    sm->option_on.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!sm->option_on.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->option_on.sprite = sfSprite_create();
    sfSprite_setTexture(sm->option_on.sprite, sm->option_on.texture, sfTrue);
    sm->option_on.pos.x = 850;
    sm->option_on.pos.y = 500;
    sfSprite_setPosition(sm->option_on.sprite, sm->option_on.pos);
    sm->option_on.rect.top = 0;
    sm->option_on.rect.left = 0;
    sm->option_on.rect.width = 240;
    sm->option_on.rect.height = 116;
    return (0);
}

int create_sprite_option_off(smenu_t *sm)
{
    char *path_to_button = "assets/buttons/option_off.png";

    sm->option_off.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!sm->option_off.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->option_off.boulean_button = false;
    sm->option_off.sprite = sfSprite_create();
    sfSprite_setTexture(sm->option_off.sprite, sm->option_off.texture, sfTrue);
    sm->option_off.pos.x = 830;
    sm->option_off.pos.y = 490;
    sfSprite_setPosition(sm->option_off.sprite, sm->option_off.pos);
    sm->option_off.rect.top = 0;
    sm->option_off.rect.left = 0;
    sm->option_off.rect.width = 240;
    sm->option_off.rect.height = 116;
    return (0);
}

void update_option_button(smenu_t *sm, rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(sm->win);
    sfFloatRect option_rect = sfSprite_getGlobalBounds(sm->option_on.sprite);

    if (sfFloatRect_contains(&option_rect, (float)mp.x, (float)mp.y)) {
        sm->option_off.boulean_button = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            rpg->prev_scene = rpg->scene;
            rpg->scene = SETTINGS;
            rpg->game_clock = sfClock_create();
        }
    } else
        sm->option_off.boulean_button = 0;
}