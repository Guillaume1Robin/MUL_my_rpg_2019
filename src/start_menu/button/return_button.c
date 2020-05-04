/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** plus.c
*/

#include "rpg.h"

int create_sprite_back_pause_menu(smenu_t *sm)
{
    sm->setting_back.texture = sfTexture_createFromFile("assets/buttons/\
arrow.png", NULL);
    if (!sm->setting_back.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->setting_back.sprite = sfSprite_create();
    sfSprite_setPosition(sm->setting_back.sprite, (sfVector2f){1697, 866});
    sfSprite_setTexture(sm->setting_back.sprite, sm->setting_back.texture, sfTrue);
    return (0);
}

void update_button_return(rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(rpg->smenu->win);
    sfFloatRect rt = sfSprite_getGlobalBounds(rpg->smenu->setting_back.sprite);

    if (sfFloatRect_contains(&rt, (float)mp.x, (float)mp.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            rpg->scene = rpg->prev_scene;
        }
    }
}