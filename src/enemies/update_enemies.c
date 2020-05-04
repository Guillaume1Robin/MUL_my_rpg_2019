/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** update_enemies.c
*/

#include "rpg.h"

static void (*mv_enemies[5])(rpg_t *, enemy_t *) = {
    [BAT] = &follow_player,
    [SLUG] = &collision_movement,
    [EGG] = &collision_movement,
    [MINIBOSS] = &collision_movement,
    [BOSS] = &boss_move
};

void animate_enemies(rpg_t *rpg)
{
    float c_time[4] = {};
    enemy_t **enms = rpg->levels[rpg->lvl]->enemies;

    for (int i = 0; i < 4; i++)
        c_time[i] = sfTime_asSeconds(sfClock_getElapsedTime(rpg->en_clock[i]));
    for (int i = 0; enms[i]; i++) {
        if (enms[i]->type == BOSS + 1)
            continue;
        if (enms[i]->alive && c_time[enms[i]->type - 1] > enms[i]->fps) {
            move_hrect(&enms[i]->rect, enms[i]->rect.width, enms[i]->max);
            sfSprite_setTextureRect(enms[i]->sprite, enms[i]->rect);
            sfClock_restart(rpg->en_clock[enms[i]->type - 1]);
        }
    }
}

void update_enemies(rpg_t *rpg)
{
    enemy_t **enms = rpg->levels[rpg->lvl]->enemies;

    for (int i = 0; enms[i]; i++) {
        if (!(enms[i]->alive))
            continue;
        mv_enemies[enms[i]->type - 1](rpg, enms[i]);
        sfSprite_setPosition(enms[i]->sprite, enms[i]->pos);
        if (enms[i]->hp <= 0 && enms[i]->type == BOSS + 1) {
            rpg->cutscenes = true;
            rpg->game_end = true;
            sfClock_restart(rpg->game_clock);
        } else if (enms[i]->hp <= 0) {
            enms[i]->alive = false;
            rpg->xp += enms[i]->type > 3 ? enms[i]->type : 1;
        }
    }
    animate_enemies(rpg);
}