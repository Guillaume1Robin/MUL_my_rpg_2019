/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pause_button_menu.c
*/

#include "rpg.h"

int create_sprite_resume_button_on(smenu_t *sm)
{
    char *path_to_button = "assets/buttons/resume_on.png";

    sm->resume_on.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!sm->resume_on.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->resume_on.sprite = sfSprite_create();
    sfSprite_setTexture(sm->resume_on.sprite, sm->resume_on.texture, sfTrue);
    sm->resume_on.pos.x = 850;
    sm->resume_on.pos.y = 350;
    sfSprite_setPosition(sm->resume_on.sprite, sm->resume_on.pos);
    sm->resume_on.rect.top = 0;
    sm->resume_on.rect.left = 0;
    sm->resume_on.rect.width = 240;
    sm->resume_on.rect.height = 116;
    return (0);
}

int create_sprite_resume_off(smenu_t *sm)
{
    char *path_to_button = "assets/buttons/resume_off.png";

    sm->resume_off.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!sm->resume_off.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->resume_off.boulean_button = false;
    sm->resume_off.sprite = sfSprite_create();
    sfSprite_setTexture(sm->resume_off.sprite, sm->resume_off.texture, sfTrue);
    sm->resume_off.pos.x = 830;
    sm->resume_off.pos.y = 340;
    sfSprite_setPosition(sm->resume_off.sprite, sm->resume_off.pos);
    sm->resume_off.rect.top = 0;
    sm->resume_off.rect.left = 0;
    sm->resume_off.rect.width = 240;
    sm->resume_off.rect.height = 116;
    return (0);
}

void update_resume_button(smenu_t *sm, rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(sm->win);
    sfFloatRect resume_rect = sfSprite_getGlobalBounds(sm->resume_on.sprite);

    if (sfFloatRect_contains(&resume_rect, (float)mp.x, (float)mp.y)) {
        sm->resume_off.boulean_button = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            rpg->scene = GAME;
            rpg->game_clock = sfClock_create();
        }
    } else
        sm->resume_off.boulean_button = 0;
}