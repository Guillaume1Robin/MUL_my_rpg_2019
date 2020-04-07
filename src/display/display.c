/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display.c
*/

#include "rpg.h"

/*
* Display player and map, to be completed with enemies
*/
void display(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->window.window, sfBlack);
    sfRenderWindow_drawSprite(rpg->window.window, rpg->map.sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window.window, rpg->player.sprite, NULL);
    sfRenderWindow_display(rpg->window.window);
}