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
        enemies[i]->hp = enemies[i]->start_hp;
        enemies[i]->pos = enemies[i]->start_pos;
    }
}

bool alive_enemies(enemy_t **enemies)
{
    for (int i = 0; enemies[i]; i++)
        if (enemies[i]->alive)
            return (true);
    return (false);
}

void next(rpg_t *rpg)
{
    sfVector2f new_pos = {};

    reset_enemies(rpg->levels[rpg->lvl]->enemies);
    rpg->lvl++;
    if (rpg->lvl == 6) {
        rpg->cutscenes = sfTrue;
        sfClock_restart(rpg->game_clock);
    }
    new_pos = rpg->levels[rpg->lvl]->player_start;
    rpg->player->pos = (sfVector2f){new_pos.x + 64, new_pos.y};
}

void prev(rpg_t *rpg)
{
    sfVector2f new_pos = {};

    reset_enemies(rpg->levels[rpg->lvl]->enemies);
    rpg->lvl--;
    new_pos = rpg->levels[rpg->lvl]->player_end;
    rpg->player->pos = (sfVector2f){new_pos.x - 64, new_pos.y};
}

void change_levels(rpg_t *rpg)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(rpg->player->sprite);
    sfFloatRect end =   {
        rpg->levels[rpg->lvl]->player_end.x,
        rpg->levels[rpg->lvl]->player_end.y,
        32, 32
    };
    sfFloatRect start = {
        rpg->levels[rpg->lvl]->player_start.x,
        rpg->levels[rpg->lvl]->player_start.y,
        32, 32
    };
    if (alive_enemies(rpg->levels[rpg->lvl]->enemies))
        return;
    if (sfFloatRect_intersects(&hitbox, &end, NULL) && rpg->lvl < NB_LEVELS)
        next(rpg);
    else if (sfFloatRect_intersects(&hitbox, &start, NULL) && rpg->lvl > 0)
        prev(rpg);
}