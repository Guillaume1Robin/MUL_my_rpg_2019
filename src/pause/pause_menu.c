/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pause_menu.c
*/

#include "rpg.h"

void display_pause_button(smenu_t *smenu, rpg_t *rpg)
{
    (void)rpg;
    if (smenu->quit_off.boulean_button == 0)
        sfRenderWindow_drawSprite(smenu->win, smenu->quit_on.sprite, NULL);
    else
        sfRenderWindow_drawSprite(smenu->win, smenu->quit_off.sprite, NULL);
    if (smenu->resume_off.boulean_button == 0)
        sfRenderWindow_drawSprite(smenu->win, smenu->resume_on.sprite, NULL);
    else
        sfRenderWindow_drawSprite(smenu->win, smenu->resume_off.sprite, NULL);
    if (smenu->option_off.boulean_button == 0)
        sfRenderWindow_drawSprite(smenu->win, smenu->option_on.sprite, NULL);
    else
        sfRenderWindow_drawSprite(smenu->win, smenu->option_off.sprite, NULL);
}

void update_menu_button(rpg_t *rpg, smenu_t *sm)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(sm->win);
    sfFloatRect quit_rect = sfSprite_getGlobalBounds(sm->quit_on.sprite);

    if (sfFloatRect_contains(&quit_rect, (float)mp.x, (float)mp.y)) {
        sm->quit_off.boulean_button = 1;
        if (rpg->event.type == sfEvtMouseButtonReleased)
            rpg->scene = MENU;
    } else
        sm->quit_off.boulean_button = 0;
}

void pause_menu_loop(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        if (rpg->event.type == sfEvtClosed) {
            sfRenderWindow_close(rpg->window);
            return;
        }
        if (rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == 36)
            rpg->scene = GAME;
        update_menu_button(rpg, rpg->smenu);
        update_resume_button(rpg->smenu, rpg);
        update_option_button(rpg->smenu, rpg);
    }
    update_animation(rpg->smenu);
    sfRenderWindow_clear(rpg->smenu->win, sfBlack);
    sfRenderWindow_drawSprite(rpg->window, rpg->smenu->bg_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->smenu->boat_sprite, NULL);
    display_pause_button(rpg->smenu, rpg);
    sfRenderWindow_display(rpg->smenu->win);
}