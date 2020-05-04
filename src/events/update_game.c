/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** update_game.c
*/

#include "rpg.h"

/*
* function pointers table for player movement
*/
static void (*mv_fct[5])(rpg_t *) = {
    &move_player_up,
    &move_player_down,
    &move_player_left,
    &move_player_right,
    &stay_still,
};

void trigger_attack(rpg_t *rpg)
{
    sfVector2i targ = {};
    float cd = sfTime_asSeconds(sfClock_getElapsedTime(rpg->att.clock));

    if (rpg->att.left_clicked && cd < 0.3) {
        targ = sfMouse_getPositionRenderWindow(rpg->window);
        add_particle(&rpg->att.particle_environment, rpg->att.particle, \
        vec_op(rpg->player->pos, rpg->player->direction, '+'), to_fvec(targ));
    }
    for (size_t index = 0; index != PARTICLE_MAX; index++)
        update_particle(&rpg->att.particle_environment, \
        &rpg->att.particle[index]);
    for (size_t index = 0; index != PARTICLE_MAX; index++)
        update_particle(&rpg->att.death_environment, \
        &rpg->att.death[index]);
}

void update_game(rpg_t *rpg)
{
    trigger_attack(rpg);
    update_enemies(rpg);
    for (int i = 0; i < 5; i++) {
        if (rpg->mv[i])
            mv_fct[i](rpg);
    }
    change_levels(rpg);
    sfSprite_setPosition(rpg->player->sprite, rpg->player->pos);
    display(rpg);
    rpg->bubble.time = sfClock_getElapsedTime(rpg->bubble.clock);
    if (sfTime_asSeconds(rpg->bubble.time) > 1)
        move_bubble(rpg);
    if (rpg->player->hp <= 0)
        rpg->scene = END;
}