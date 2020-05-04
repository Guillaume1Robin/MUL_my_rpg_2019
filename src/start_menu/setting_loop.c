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
    int kes = sfKeyEscape;

    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        if (rpg->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        if (rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == kes)
            rpg->scene = rpg->prev_scene;
        update_button_plus(rpg->smenu, rpg);
        update_button_less(rpg->smenu, rpg);
        change_volume(rpg);
        update_button_return(rpg);
    }
    update_animation(rpg->smenu);
    sfRenderWindow_clear(rpg->smenu->win, sfBlack);
    sfRenderWindow_drawSprite(rpg->window, rpg->smenu->bg_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->smenu->boat_sprite, NULL);
    draw_text_box(rpg->window, rpg->smenu->text);
    display_setting(rpg->smenu);
    sfRenderWindow_display(rpg->smenu->win);
}