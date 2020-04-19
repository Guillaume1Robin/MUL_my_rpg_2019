/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** plus.c
*/

#include "rpg.h"

int create_sprite_back_menu_pause(smenu_t *sm)
{
    sm->setting_back.texture = sfTexture_createFromFile("assets/buttons/setting_back.png", NULL);
    if (!sm->setting_back.texture) {
        write(2, "error missing the button\n", 26);
        return (84);
    }
    sm->setting_back.sprite = sfSprite_create();
    sfSprite_setTexture(sm->setting_back.sprite, sm->setting_back.texture, sfTrue);
    return (0);
}

void update_button_return(rpg_t *rpg)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(rpg->smenu->win);

    if (mp.x >= 1697 && mp.x <= 1809 && mp.y >= 866 && mp.y <= 978) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            rpg->scene = MENU;
        }
    }
}

// void resize_window(rpg_t *rpg)
// {
//     if (sfKeyboard_isKeyPressed(sfKeyC)) {
//         rpg->window.mode.width = 800;
//         rpg->window.mode.height = 600;
//         rpg->window.mode.bitsPerPixel = 32;
//     }
// }
