/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** enemy_movement.c
*/

#include "rpg.h"

void damage_player(rpg_t * rpg, enemy_t *en)
{
    add_square(&rpg->att.death_environment, \
    rpg->att.death, rpg->player->pos);
    rpg->player->hp -= en->damage;
}

void collision_movement(rpg_t *rpg, enemy_t *en)
{
    player_t *pl = rpg->player;
    sfVector2f delta = {pl->pos.x - en->pos.x, pl->pos.y - en->pos.y};
    float angle = atan2f(delta.y, delta.x);
    sfVector2f velocity = {cosf(angle), sinf(angle)};
    sfFloatRect rect = sfSprite_getGlobalBounds(en->sprite);
    sfFloatRect player_rect = sfSprite_getGlobalBounds(rpg->player->sprite);

    if (!sfFloatRect_intersects(&rect, &player_rect, NULL)) {
        if (sfSprite_getScale(en->sprite).x > 0 && velocity.x > 0) {
            sfSprite_scale(en->sprite, (sfVector2f){-1, 1});
        } else if (sfSprite_getScale(en->sprite).x < 0 && velocity.x < 0)
            sfSprite_scale(en->sprite, (sfVector2f){-1, 1});
    } else
        damage_player(rpg, en);
    if (rpg->att.left_clicked)
        coll_knockback(en, rpg, velocity);
    velocity.x = (en->speed * velocity.x) / 4;
    velocity.y = (en->speed * velocity.y) / 4;
    enemy_collisions(rpg, &(en->pos), velocity);
}

void follow_player(rpg_t *rpg, enemy_t *en)
{
    player_t *pl = rpg->player;
    sfVector2f delta = {pl->pos.x - en->pos.x, pl->pos.y - en->pos.y};
    float angle = atan2f(delta.y, delta.x);
    sfVector2f velocity = {cosf(angle), sinf(angle)};
    sfVector2f scale = sfSprite_getScale(en->sprite);
    sfFloatRect rect = sfSprite_getGlobalBounds(en->sprite);
    sfFloatRect player_rect = sfSprite_getGlobalBounds(rpg->player->sprite);

    if (!sfFloatRect_intersects(&rect, &player_rect, NULL)) {
        if (scale.x > 0 && velocity.x > 0) {
            sfSprite_scale(en->sprite, (sfVector2f){-1, 1});
        } else if (scale.x < 0 && velocity.x < 0)
            sfSprite_scale(en->sprite, (sfVector2f){-1, 1});
    } else
        damage_player(rpg, en);
    en->pos.x += (en->speed * velocity.x) / 2;
    en->pos.y += (en->speed * velocity.y) / 2;
    if (rpg->att.left_clicked)
        knockback(en, rpg, velocity);
}