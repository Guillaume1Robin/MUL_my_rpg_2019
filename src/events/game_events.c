/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** game_events.c
*/

#include "rpg.h"

void mouse_click_event(attack_t *attack, sfEvent event)
{
    float cd = sfTime_asSeconds(sfClock_getElapsedTime(attack->clock));

    if (event.type == sfEvtMouseButtonReleased)
            attack->left_clicked = sfFalse;
    if (sfMouse_isButtonPressed(sfMouseLeft) && cd > 0.6) {
        attack->left_clicked = sfTrue;
        sfClock_restart(attack->clock);
    }
}

void game_events(rpg_t *rpg)
{
    int kes = sfKeyEscape;

    if (rpg->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == kes) {
        rpg->prev_scene = GAME;
        rpg->scene = PAUSE;
    }
    set_movement(rpg);
    change_volume(rpg);
    mouse_click_event(&rpg->att, rpg->event);
    open_inventory(rpg);
    open_merchant(rpg);
    update_npc(rpg);
}