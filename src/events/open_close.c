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
void open_close_events(sfEvent *event, sfRenderWindow *win)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(win);
    else if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
        sfRenderWindow_close(win);
}