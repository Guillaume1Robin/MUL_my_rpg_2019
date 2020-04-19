/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setting_loop.c
*/

#include "rpg.h"

void display_setting(smenu_t *smenu)
{
    sfRenderWindow_drawSprite(smenu->win, smenu->setting_back.sprite, NULL);
    if (smenu->plus_off.boulean_button == 0)
        sfRenderWindow_drawSprite(smenu->win, smenu->plus_on.sprite, NULL);
    else
        sfRenderWindow_drawSprite(smenu->win, smenu->plus_off.sprite, NULL);
    if (smenu->less_off.boulean_button == 0)
        sfRenderWindow_drawSprite(smenu->win, smenu->less_on.sprite, NULL);
    else
        sfRenderWindow_drawSprite(smenu->win, smenu->less_off.sprite, NULL);
}

void settings_loop(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->smenu->win, &rpg->smenu->event)) {
        open_close_events(rpg, &rpg->smenu->event, rpg->smenu->win);
        update_button_plus(rpg->smenu, rpg);
        update_button_less(rpg->smenu, rpg);
        change_volume(rpg);
        update_button_return(rpg);
        // resize_window(rpg);
    }
    sfRenderWindow_clear(rpg->smenu->win, sfBlack);
    display_setting(rpg->smenu);
    sfRenderWindow_display(rpg->smenu->win);
}