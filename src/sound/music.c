/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** music.c
*/

#include "rpg.h"

void init_music(rpg_t *rpg)
{
    rpg->music = sfMusic_createFromFile("assets/sounds/sound_menu.ogg");
    rpg->volume = 15.0;
}

void play_music(rpg_t *rpg)
{
    sfMusic_play(rpg->music);
    sfMusic_setLoop(rpg->music, sfTrue);
}

void change_volume(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyP) && rpg->volume <= 90) {
        rpg->volume += 10;
    }
    if (sfKeyboard_isKeyPressed(sfKeyM) && rpg->volume >= 10) {
        rpg->volume -= 10;
    }
    if (sfKeyboard_isKeyPressed(sfKeyF3)) {
        sfMusic_pause(rpg->music);
    }
}