/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_setting.c
*/

#include "rpg.h"

int create_sprite_button_setting_on(smenu_t *sm)
{
    char *path_to_button = "assets/buttons/setting_on.png";

    sm->setting_on.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!sm->setting_on.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->setting_on.sprite = sfSprite_create();
    sfSprite_setTexture(sm->setting_on.sprite, sm->setting_on.texture, sfTrue);
    sm->setting_on.pos.x = 10;
    sm->setting_on.pos.y = 10;
    sfSprite_setPosition(sm->setting_on.sprite, sm->setting_on.pos);
    sm->setting_on.rect.top = 0;
    sm->setting_on.rect.left = 0;
    sm->setting_on.rect.width = 125;
    sm->setting_on.rect.height = 125;
    return (0);
}

int create_sprite_setting_off(smenu_t *sm)
{
    char *path_to_button = "assets/buttons/setting_off.png";

    sm->setting_off.texture = sfTexture_createFromFile(path_to_button, NULL);
    if (!sm->setting_off.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->setting_off.sprite = sfSprite_create();
    sfSprite_setTexture(sm->setting_off.sprite, sm->setting_off.texture\
, sfTrue);
    sm->setting_off.pos.x = 10;
    sm->setting_off.pos.y = 10;
    sfSprite_setPosition(sm->setting_off.sprite, sm->setting_off.pos);
    sm->setting_off.rect.top = 0;
    sm->setting_off.rect.left = 0;
    sm->setting_off.rect.width = 125;
    sm->setting_off.rect.height = 125;
    return (0);
}

void update_button_setting(rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(rpg->smenu->win);
    sfFloatRect rect = sfSprite_getGlobalBounds(rpg->smenu->setting_on.sprite);

    if (sfFloatRect_contains(&rect, (float)mp.x, (float)mp.y)) {
        rpg->smenu->setting_off.boulean_button = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            rpg->prev_scene = rpg->scene;
            rpg->scene = SETTINGS;
        }
    } else
        rpg->smenu->setting_off.boulean_button = 0;
}