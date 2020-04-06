/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create.c
*/

#include "rpg.h"

void create(rpg_t *rpg)
{
    // create_window(rpg);
    rpg->smenu = create_menu();
    create_map(rpg);
    rpg->smenu->win = rpg->window.window;
    create_player(rpg);
}