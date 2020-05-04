/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** enemy_collisions.c
*/

#include "rpg.h"

void knockback(enemy_t *enemy, rpg_t *rpg, sfVector2f velocity)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(enemy->sprite);
    sfVector2f part_pos = {};

    for (size_t i = 0; i < PARTICLE_MAX; i++) {
        part_pos = rpg->att.particle[i].pos;
        if (rpg->att.particle[i].living && \
        sfFloatRect_contains(&rect, part_pos.x, part_pos.y)) {
            enemy->pos.x += (velocity.x / 2) * enemy->knockback;
            enemy->pos.y += (velocity.y / 2) * enemy->knockback;
            enemy->hp -= rpg->player->damage + rpg->potion;
            rpg->att.particle[i].living = false;
            add_square(&rpg->att.death_environment, rpg->att.death, \
            enemy->pos);
        }
    }
}

void coll_knockback(enemy_t *enemy, rpg_t *rpg, sfVector2f velocity)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(enemy->sprite);
    sfVector2f part_pos = {};
    sfVector2f kb = {
        (velocity.x / 2) * enemy->knockback,
        (velocity.y / 2) * enemy->knockback
    };

    for (size_t i = 0; i < PARTICLE_MAX; i++) {
        part_pos = rpg->att.particle[i].pos;
        if (rpg->att.particle[i].living && \
        sfFloatRect_contains(&rect, part_pos.x, part_pos.y)) {
            enemy_collisions(rpg, &(enemy->pos), kb);
            enemy->hp -= rpg->player->damage + rpg->potion;
            rpg->att.particle[i].living = false;
            add_square(&rpg->att.death_environment, rpg->att.death, \
            enemy->pos);
        }
    }
}

void enemy_collisions(rpg_t *rpg, sfVector2f *pos, sfVector2f velocity)
{
    sfVector2f grid = {32, 32};
    sfVector2f ud_pos = {pos->x + velocity.x, pos->y};
    sfVector2i grid_pos = to_ivec(vec_op(ud_pos, grid, '/'));
    level_t *curr_lvl = rpg->levels[rpg->lvl];

    if (!curr_lvl->collisions[grid_pos.y][grid_pos.x])
        pos->x += velocity.x;
    ud_pos = (sfVector2f){ud_pos.x - velocity.x, pos->y + velocity.y};
    grid_pos = to_ivec(vec_op(ud_pos, grid, '/'));
    if (!curr_lvl->collisions[grid_pos.y][grid_pos.x])
        pos->y += velocity.y;
}