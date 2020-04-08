/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include "basic.h"
    #define NB_LEVELS 5

    typedef struct clock_rpg_s
    {
        sfTime time;
        sfClock *clock;
    } clock_rpg_t;

    typedef struct player_s
    {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f size;
        sfVector2f pos;
        sfIntRect rect;
    } player_t;

    typedef struct window_s
    {
        sfRenderWindow *window;
        sfVideoMode mode;
    } window_t;

    typedef struct map_s
    {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        int **map;
        int **enemies;
    } map_t;

    typedef struct run_s
    {
        map_t *levels;
        size_t nb_levels;
    } run_t;

    typedef struct rpg_s
    {
        int bool_menu;
        sfEvent *event;
        clock_rpg_t clock_move_rect_player;
        player_t player;
        window_t window;
        map_t map;
        run_t run;
        smenu_t *smenu;
    } rpg_t;

#endif