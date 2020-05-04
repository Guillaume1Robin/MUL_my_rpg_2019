/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** end_loop.c
*/

#include "rpg.h"

void reset_game(rpg_t *rpg)
{
    char *txt = "Your son is held captive by monsters! Go get him!";

    rpg->scene = MENU;
    sfClock_restart(rpg->game_clock);
    sfClock_restart(rpg->boss_phases);
    for (int i = 0; i < 4; i++)
        sfClock_restart(rpg->en_clock[i]);
    destroy_levels(rpg->levels);
    rpg->levels = create_game_layout(NB_LEVELS);
    rpg->lvl = 0;
    rpg->player->hp = 500;
    rpg->player->pos = rpg->levels[0]->player_start;
    sfText_setString(rpg->text.stc, txt);
}

void disp_end_loop(rpg_t *rpg)
{
    update_animation(rpg->smenu);
    sfRenderWindow_clear(rpg->smenu->win, sfBlack);
    sfRenderWindow_drawSprite(rpg->window, rpg->smenu->bg_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->smenu->boat_sprite, NULL);
    draw_text_box(rpg->window, rpg->end_screen);
    sfRenderWindow_drawSprite(rpg->window, rpg->title.sprite, NULL);
    sfRenderWindow_display(rpg->smenu->win);
}

void end_loop(rpg_t *rpg)
{
    char *death = "You failed to rescue your son!\n\n\
The monsters threw you on a boat to get you away\n\
You have to come back at them!\nThey left you the objects you had!\
 How foolish!\n\nPress ESC to exact your revenge!";
    char *victory = "\tYou saved your son and gave him a brand new boat!\n\n\
\tHe went on sea to test it, let's hope he isn't abducted this time!\n\n\n\
\tPress ESC to go check on him";
    int kes = sfKeyEscape;

    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        if (rpg->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        if (rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == kes)
            reset_game(rpg);
    }
    if (rpg->player->hp <= 0) {
        sfText_setString(rpg->end_screen.stc, death);
    } else {
        sfText_setString(rpg->end_screen.stc, victory);
    }
    disp_end_loop(rpg);
}
