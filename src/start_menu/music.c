/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** music.c
*/

#include "rpg.h"

void init_music(rpg_t *rpg)
{
    rpg->music = sfMusic_createFromFile("button/sound_menu.ogg");
    rpg->volume = 50;
}

void play_music(rpg_t *rpg)
{
    sfMusic_play(rpg->music);
    sfMusic_setLoop(rpg->music, sfTrue);
}

void change_voume(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyP) && rpg->volume <= 90) {
        rpg->volume += 10;
    }
    if (sfKeyboard_isKeyPressed(sfKeyM) && rpg->volume >= 10) {
        rpg->volume -= 10;
    }
}