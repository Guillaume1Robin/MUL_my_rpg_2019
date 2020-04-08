/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** open_close.c
*/

#include "rpg.h"

/*
* Basic closing events: esc and cross
*/
void open_close_events(rpg_t *rpg, sfEvent *event, sfRenderWindow *win)
{
    if (event->type == sfEvtClosed) {
        sfMusic_destroy(rpg->music);
        sfRenderWindow_close(win);
        return;
    } else if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
        sfRenderWindow_close(win);
}