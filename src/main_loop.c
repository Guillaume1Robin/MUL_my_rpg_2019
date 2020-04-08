/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** open_window.c
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

/*
* Scenes or menus ? 
* We can make pseudo-inheritance: scenes are some kind of menus but their functions will be malloc'ed
*/
static void (*scenes[2])(rpg_t *) = {
    &menu_loop,
    &game_loop,
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
    while (sfRenderWindow_pollEvent(rpg->window.window, rpg->event)) {
        open_close_events(rpg->event, rpg->window.window);
        set_movement(rpg);
    }
    for (int i = 0; i < 5; i++) {
        if (rpg->mv[i])
            mv_fct[i](rpg);
    }
    sfSprite_setPosition(rpg->player.sprite, rpg->player.pos);
    display(rpg);
}

/*
* Plays which loop we are on,
which scene we are on.
*/
void main_loop(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->window.window)) {
        scenes[rpg->scene](rpg);
        printf("scene : %d\n", rpg->scene);
    }
    sfRenderWindow_destroy(rpg->window.window);
}