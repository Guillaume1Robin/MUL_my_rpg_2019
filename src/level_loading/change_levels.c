/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** change_levels.c
*/

#include "rpg.h"

void reset_enemies(enemy_t **enemies)
{
    for (int i = 0; enemies[i]; i++) {
        enemies[i]->alive = sfTrue;
        enemies[i]->hp = enemies[i]->type + 1;
        enemies[i]->pos = enemies[i]->start_pos;
    }
}

void change_levels(rpg_t *rpg)
{
    sfVector2f new_pos = {0};
    sfFloatRect hitbox = sfSprite_getGlobalBounds(rpg->player->sprite);
    sfFloatRect end =   {rpg->levels[rpg->lvl]->player_end.x,
                        rpg->levels[rpg->lvl]->player_end.y,
                        32, 32};
    sfFloatRect start = {rpg->levels[rpg->lvl]->player_start.x,
                        rpg->levels[rpg->lvl]->player_start.y,
                        32, 32};
    if (sfFloatRect_intersects(&hitbox, &end, NULL) && rpg->lvl < MAX_LEVEL) {
        reset_enemies(rpg->levels[rpg->lvl]->enemies);
        rpg->lvl++;
        if (rpg->lvl == MAX_LEVEL)
            rpg->cutscenes = sfTrue;
        new_pos = rpg->levels[rpg->lvl]->player_start;
        rpg->player->pos = (sfVector2f){new_pos.x + 64, new_pos.y};
    } else if (sfFloatRect_intersects(&hitbox, &start, NULL) && rpg->lvl > 0) {
        reset_enemies(rpg->levels[rpg->lvl]->enemies);
        rpg->lvl--;
        new_pos = rpg->levels[rpg->lvl]->player_end;
        rpg->player->pos = (sfVector2f){new_pos.x - 64, new_pos.y};
    }
}