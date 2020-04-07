/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** basic.h
*/

#ifndef BASIC_H_
    #define BASIC_H_

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include "my.h"

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
    } map_t;

    typedef struct button_s
    {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f size;
        sfVector2f pos;
        sfIntRect rect;
        int boulen_button;
    } button_t;

    typedef struct menu_s
    {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        sfIntRect rect;
    } menu_t;

    typedef struct smenu_s{
        sfRenderWindow *win;
        sfEvent event;
        sfIntRect sprite_rect;
        menu_t sky;
        menu_t **para;
        button_t play_on;
        button_t play_off;
        button_t save_on;
        button_t save_off;
        button_t quit_on;
        button_t quit_off;
        button_t htp_on;
        button_t htp_off;
    } smenu_t;

    typedef struct rpg_s
    {
        int scene;
        int mv[5];
        sfEvent *event;
        clock_rpg_t clock_display;
        clock_rpg_t clock_player;
        clock_rpg_t clock_move_rect_player;
        player_t player;
        window_t window;
        map_t map;
        smenu_t *smenu;
    } rpg_t;

    void open_close_events(sfEvent *event, sfRenderWindow *win);

#endif