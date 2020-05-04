/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_enemy.c
*/

#include "rpg.h"

void draw_enemies(rpg_t *rpg)
{
    enemy_t **enemies = rpg->levels[rpg->lvl]->enemies;

    for (int i = 0; enemies && enemies[i]; i++) {
        if (enemies[i]->alive)
            sfRenderWindow_drawSprite(rpg->window, enemies[i]->sprite, NULL);
    }
}
