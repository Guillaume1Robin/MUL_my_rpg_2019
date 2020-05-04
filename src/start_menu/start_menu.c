/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu_principal.c
*/

#include "rpg.h"

void display_button(smenu_t *smenu)
{
    if (smenu->play_off.boulean_button == 0)
        sfRenderWindow_drawSprite(smenu->win, smenu->play_on.sprite, NULL);
    else
        sfRenderWindow_drawSprite(smenu->win, smenu->play_off.sprite, NULL);
    if (smenu->htp_off.boulean_button == 0)
        sfRenderWindow_drawSprite(smenu->win, smenu->htp_on.sprite, NULL);
    else
        sfRenderWindow_drawSprite(smenu->win, smenu->htp_off.sprite, NULL);
    if (smenu->quit_off.boulean_button == 0)
        sfRenderWindow_drawSprite(smenu->win, smenu->quit_on.sprite, NULL);
    else
        sfRenderWindow_drawSprite(smenu->win, smenu->quit_off.sprite, NULL);
    if (smenu->setting_off.boulean_button == 0)
        sfRenderWindow_drawSprite(smenu->win, smenu->setting_on.sprite, NULL);
    else
        sfRenderWindow_drawSprite(smenu->win, smenu->setting_off.sprite, NULL);
}

void update_animation(smenu_t *menu)
{
    float sec = sfTime_asSeconds(sfClock_getElapsedTime(menu->anim[0]));

    if (sec > 0.0625) {
        if (move_hrect(&menu->bg_rect, 341, 2387))
            move_vrect(&menu->bg_rect, 192, 2496);
        sfSprite_setTextureRect(menu->bg_sprite, menu->bg_rect);
        sfClock_restart(menu->anim[0]);
    }
    sec = sfTime_asSeconds(sfClock_getElapsedTime(menu->anim[1]));
    if (sec > 0.1) {
        move_hrect(&menu->boat_rect, 341, 2387);
        sfSprite_setTextureRect(menu->boat_sprite, menu->boat_rect);
        sfClock_restart(menu->anim[1]);
    }
}

void open_close_events(sfEvent *event, sfRenderWindow *win)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(win);
}

void menu_loop(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->smenu->win, &rpg->smenu->event)) {
        open_close_events(&rpg->smenu->event, rpg->smenu->win);
        update_button_play(rpg->smenu, rpg);
        update_button_quit(rpg->smenu);
        update_button_how_to_play(rpg);
        update_button_setting(rpg);
    }
    update_animation(rpg->smenu);
    sfRenderWindow_clear(rpg->smenu->win, sfBlack);
    sfRenderWindow_drawSprite(rpg->window, rpg->smenu->bg_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->smenu->boat_sprite, NULL);
    display_button(rpg->smenu);
    sfRenderWindow_drawSprite(rpg->window, rpg->title.sprite, NULL);
    sfRenderWindow_display(rpg->smenu->win);
}