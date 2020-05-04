/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** cutscene_events.c
*/

#include "rpg.h"

void cutscene_events(rpg_t *rpg)
{
    int kes = sfKeyEscape;

    if (rpg->smenu->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == kes) {
        rpg->scene = PAUSE;
        rpg->cutscenes = sfFalse;
    }
    if (rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == sfKeyTab)
        rpg->cutscenes = sfFalse;
}