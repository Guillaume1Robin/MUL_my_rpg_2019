/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** open_window.c
*/

#include "rpg.h"

static void (*loop[])(rpg_t *) = {
    [MENU] = &menu_loop,
    [GAME] = &game_loop,
    [SETTINGS] = &settings_loop,
    [INVENTORY] = &inventory_loop,
    [MERCHANT] = &merchant_loop,
    [PAUSE] = &pause_menu_loop,
    [HTP] = &htp_loop,
    [END] = &end_loop,
    [NPC] = &npc_loop,
};

/*
* Game_loop which is basically level 1 right now
* Will it always be level 1 or the basis for the scenes ?
Got to figure out which events and functions are always played in a level and the ones are specific to scene:
    - open_close
    - player_movement and attack
    - merchant
    - loot pickup
    - basic enemies movement and attack
    - intermediate enemies movement and attack
    - hard enemies movement and attack
    - boss movement and attack
    - hp/death updates
* One scene shall always have the same rules but maybe we can implement modules so that we can add bosses just like that ?
*/
void game_loop(rpg_t *rpg)
{
    if (rpg->cutscenes)
        return (play_cutscene(rpg));
    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        game_events(rpg);
    }
    update_game(rpg);
}

void main_loop(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->window)) {
        sfMusic_setVolume(rpg->music, rpg->volume);
        loop[rpg->scene](rpg);
    }
}