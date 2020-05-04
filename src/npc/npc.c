/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** npc.c
*/

#include "rpg.h"

void update_npc(rpg_t *rpg)
{
    if (rpg->player->pos.x >= rpg->npc.pos.x - 100 && \
    rpg->player->pos.x <= rpg->npc.pos.x + 160 && \
    rpg->player->pos.y >= rpg->npc.pos.y - 100 && \
    rpg->player->pos.y <= rpg->npc.pos.y + 200) {
        rpg->bool_npc = 1;
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            rpg->scene = NPC;
            sfClock_restart(rpg->npc_clock);
        }
    } else
        rpg->bool_npc = 0;
}

void draw_npc_two(rpg_t *rpg)
{
    float sec = sfTime_asSeconds(sfClock_getElapsedTime(rpg->npc_clock));
    draw_attacks(rpg);
    if (rpg->bool_npc == 1)
        sfRenderWindow_drawSprite(rpg->window, rpg->bubble.sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->npc.sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->box_npc.sprite, NULL);
    if (sec < 3)
        sfRenderWindow_drawText(rpg->window, rpg->text_npc.stc, NULL);
    else if (sec < 4.5)
        sfRenderWindow_drawText(rpg->window, rpg->text2_npc.stc, NULL);
    else
        rpg->scene = GAME;
}

void draw_npc(rpg_t *rpg)
{
    level_t *curr_level = rpg->levels[rpg->lvl];

    sfRenderWindow_drawSprite(rpg->window, curr_level->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->player->sprite, NULL);
    draw_enemies(rpg);
    draw_stat(rpg);
    sfRenderWindow_drawSprite(rpg->window, curr_level->ol_sprite, NULL);
    if (rpg->cutscenes == sfTrue)
        draw_text_box(rpg->window, rpg->text);
    draw_npc_two(rpg);
}

void npc_loop(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        game_events(rpg);
    }
    sfRenderWindow_clear(rpg->window, sfBlack);
    draw_npc(rpg);
    sfRenderWindow_display(rpg->window);
}
