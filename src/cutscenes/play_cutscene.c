/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** play_cutscene.c
*/

#include "rpg.h"

void text_cutscene(rpg_t *rpg, float seconds)
{
    char *text1 = "Throw something into the foutain to buy gear";
    char *text2 = "This will allow you to defeat the monsters";
    char *text3 = "and to save your son from their claws!";

    if (seconds > 2)
        sfText_setString(rpg->text.stc, "You must find him before trouble!");
    if (seconds > 4)
        sfText_setString(rpg->text.stc, text1);
    if (seconds > 6)
        sfText_setString(rpg->text.stc, text2);
    if (seconds > 8)
        sfText_setString(rpg->text.stc, text3);
}

void start_cutscene(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->game_clock);
    float seconds = sfTime_asSeconds(time);

    text_cutscene(rpg, seconds);
    if (seconds < 1.5)
        return (move_player_right(rpg));
    if (seconds < 2)
        return (move_player_down(rpg));
    if (seconds < 2.5)
        return (move_player_up(rpg));
    if (seconds < 3)
        return (move_player_right(rpg));
    if (seconds > 10)
        rpg->cutscenes = sfFalse;
}

void end_cutscene(rpg_t *rpg)
{
    rpg->cutscenes = sfFalse;
}

void play_cutscene(rpg_t *rpg)
{
    if (rpg->lvl == 0) {
        start_cutscene(rpg);
    } else if (rpg->lvl == MAX_LEVEL)
        end_cutscene(rpg);
    else
        rpg->cutscenes = sfFalse;
    sfSprite_setPosition(rpg->player->sprite, rpg->player->pos);
    display(rpg);
}