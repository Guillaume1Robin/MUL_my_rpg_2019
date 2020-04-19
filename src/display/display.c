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
    level_t *curr_level = rpg->levels[rpg->lvl];

    sfRenderWindow_clear(rpg->window, sfBlack);
    //sfRenderWindow_drawSprite(rpg->window, rpg->map.sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, curr_level->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->player->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, curr_level->ol_sprite, NULL);
    if (rpg->cutscenes == sfTrue) {
        sfRenderWindow_drawSprite(rpg->window, rpg->text.box_sprite, NULL);
        sfRenderWindow_drawText(rpg->window, rpg->text.stc, NULL);
    }
    sfRenderWindow_display(rpg->window);
}