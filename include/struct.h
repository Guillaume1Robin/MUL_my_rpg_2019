/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include "basic.h"
    #include "start_menu.h"

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
    } map_t;

    typedef struct rpg_s
    {
        int bool_menu;
        sfEvent *event;
        clock_rpg_t clock_display;
        clock_rpg_t clock_player;
        clock_rpg_t clock_move_rect_player;
        player_t player;
        window_t window;
        map_t map;
        smenu_t *smenu;
    } rpg_t;

    int initialise_value_struct(rpg_t *rpg);

    int create_window(rpg_t *rpg);

    int create_map(rpg_t *rpg);

    int create_player(rpg_t *rpg);

    void create(rpg_t *rpg);

    void display(rpg_t *rpg);

    void open_window(rpg_t *rpg);

    void move_player(rpg_t *rpg);

    void clock_display(rpg_t *rpg);

    void clock_player(rpg_t *rpg);

    void clock_move_rect_player(rpg_t *rpg);

    sfIntRect move_init2(smenu_t *smenu);

    int **collision_parser(char const *map_path);

#endif