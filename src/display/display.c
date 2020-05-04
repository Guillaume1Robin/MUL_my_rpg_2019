/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display.c
*/

#include "rpg.h"

void draw_attacks(rpg_t *rpg)
{
    for (size_t index = 0; index < PARTICLE_MAX; index++)
        display_particle(rpg->window, &rpg->att.particle[index], \
        rpg->att.particle_environment.shape);
    for (size_t index = 0; index < PARTICLE_MAX; index++)
        display_particle(rpg->window, &rpg->att.death[index], \
        rpg->att.death_environment.shape);
}

/*
* Display player and map, to be completed with enemies
*/

void draw_stat(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->xp_box.box_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->hp_box.box_sprite, NULL);
    sfText_setString(rpg->xp_nb.stc, my_itos(rpg->xp));
    sfRenderWindow_drawText(rpg->window, rpg->xp_nb.stc, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->xp_text.stc, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->hp_text.stc, NULL);
    sfText_setString(rpg->hp_nb.stc, my_itos(rpg->player->hp));
    sfRenderWindow_drawText(rpg->window, rpg->hp_nb.stc, NULL);
}

void display(rpg_t *rpg)
{
    level_t *curr_level = rpg->levels[rpg->lvl];

    sfRenderWindow_clear(rpg->window, sfBlack);
    sfRenderWindow_drawSprite(rpg->window, curr_level->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->player->sprite, NULL);
    draw_attacks(rpg);
    draw_enemies(rpg);
    sfRenderWindow_drawSprite(rpg->window, curr_level->ol_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->softest->sprite, NULL);
    draw_stat(rpg);
    if (rpg->cutscenes == sfTrue)
        draw_text_box(rpg->window, rpg->text);
    if (rpg->lvl == 0) {
        if (rpg->bool_npc == 1)
            sfRenderWindow_drawSprite(rpg->window, rpg->bubble.sprite, NULL);
        sfRenderWindow_drawSprite(rpg->window, rpg->npc.sprite, NULL);
    }
    sfRenderWindow_display(rpg->window);
}