/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** open_window.c
*/

#include "rpg.h"

void open_window(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->window.window)) {
        if (rpg->smenu->bool) {
            menu_loop(rpg->smenu);
            continue;
        }
        while (sfRenderWindow_pollEvent(rpg->window.window, rpg->event))
            open_close_events(rpg->event, rpg->window.window);
        clock_player(rpg);
        clock_move_rect_player(rpg);
        clock_display(rpg);
    }
    sfRenderWindow_destroy(rpg->window.window);
}