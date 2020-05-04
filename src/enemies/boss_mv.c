/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** boss_mv.c
*/

#include "rpg.h"

void dash(enemy_t *enemy, sfVector2f target, int phase)
{
    sfVector2f delta = {
        target.x - enemy->pos.x,
        target.y - enemy->pos.y
    };
    float angle = atan2f(delta.y, delta.x);
    float x = cosf(angle);
    float y = sinf(angle);

    enemy->pos.x += (enemy->speed * x * phase) / 2;
    enemy->pos.y += (enemy->speed * y * phase) / 2;
}

void tp_circle(int radius, enemy_t *enemy, sfVector2f target)
{
    float angle = ((float)rand()/(float)(RAND_MAX)) * 2 * PI;
    float x = cos(angle) * radius + target.x;
    float y = sin(angle) * radius + target.y;

    enemy->pos.x = x;
    enemy->pos.y = y;
}

void phase_one(rpg_t *rpg, enemy_t *enemy, sfClock *phases, float div)
{
    static float prev = 0;
    float time = sfTime_asSeconds(sfClock_getElapsedTime(phases));

    if (prev - time > 0)
        prev = 0;
    if (prev - time < -1 / div) {
        tp_circle(300, enemy, rpg->player->pos);
        prev = time;
    }
    enemy->pos.x += -3 + ((float)rand()/(float)(RAND_MAX)) * 6;
    enemy->pos.y += -3 + ((float)rand()/(float)(RAND_MAX)) * 6;
}

void phase_three(rpg_t *rpg, enemy_t *enemy, sfClock *phases, float div)
{
    static float prev = 0;
    float time = sfTime_asSeconds(sfClock_getElapsedTime(phases));
    static sfVector2f target = {WIDTH / 2, HEIGHT / 2};

    if (prev - time > 0)
        prev = 0;
    if (prev - time < -1.5 / div) {
        target = rpg->player->pos;
        prev = time;
    } else {
        dash(enemy, target, (int)div);
    }
    enemy->pos.x += -3 + ((float)rand()/(float)(RAND_MAX)) * 6;
    enemy->pos.y += -3 + ((float)rand()/(float)(RAND_MAX)) * 6;
}

void boss_move(rpg_t *rpg, enemy_t *enemy)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(rpg->boss_phases));
    static float phase = 1;
    sfFloatRect pr = sfSprite_getGlobalBounds(rpg->player->sprite);
    sfFloatRect er = sfSprite_getGlobalBounds(enemy->sprite);

    phase = enemy->hp > enemy->start_hp / 2 ? 1 : 2;
    enemy->rect = phase == 2 ? (sfIntRect){64, 0, 64, 64} : enemy->rect;
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    if (time > 7.0 / phase)
        sfClock_restart(rpg->boss_phases);
    if (time < 4 / phase)
        phase_one(rpg, enemy, rpg->boss_phases, phase);
    else if (time < 5.5 / phase) {
        enemy->pos.x += -3 + ((float)rand()/(float)(RAND_MAX)) * 6;
        enemy->pos.y += -3 + ((float)rand()/(float)(RAND_MAX)) * 6;
    } else
        phase_three(rpg, enemy, rpg->boss_phases, phase);
    if (sfFloatRect_intersects(&pr, &er, NULL))
        damage_player(rpg, enemy);
    knockback(enemy, rpg, (sfVector2f){});
}