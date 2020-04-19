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
    #include <math.h>
    #include "my.h"

    typedef struct text_s {
        char *string;
        sfSprite *box_sprite;
        sfTexture *box_texture;
        sfText *stc;
        sfFont *font;
        sfVector2f pos;
    } text_t;

    typedef struct player_s
    {
        int hp;
        int money;
        int damage;
        float speed;
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f size;
        sfVector2f pos;
        sfIntRect rect;
        sfClock *clock;
        sfClock *damages;
    } player_t;

    typedef struct enemy_s
    {
        int type;
        int hp;
        int damage;
        sfBool alive;
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect;
        sfVector2f start_pos;
        sfVector2f pos;
    } enemy_t;

    typedef struct level_s
    {
        sfVector2f merch_pos;
        sfVector2f player_start;
        sfVector2f player_end;
        int nb_enemies;
        enemy_t **enemies;
        int **collisions;
        sfTexture *texture;
        sfSprite *sprite;
        sfTexture *ol_texture;
        sfSprite *ol_sprite;
        sfVector2f pos;
    } level_t;

    typedef struct button_s
    {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f size;
        sfVector2f pos;
        sfIntRect rect;
        int boulean_button;
    } button_t;

    typedef struct parallax_s
    {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        sfIntRect rect;
    } parallax_t;

    typedef struct smenu_s{
        sfRenderWindow *win;
        sfEvent event;
        sfIntRect sprite_rect;
        parallax_t **para;
        button_t play_on;
        button_t play_off;
        button_t save_on;
        button_t save_off;
        button_t quit_on;
        button_t quit_off;
        button_t htp_on;
        button_t htp_off;
        button_t setting_on;
        button_t setting_off;
        button_t setting_back;
        button_t plus_on;
        button_t plus_off;
        button_t less_on;
        button_t less_off;
    } smenu_t;

    typedef struct rpg_s
    {
        int scene;
        int lvl;
        int mv[5];
        sfEvent event;
        player_t *player;
        sfRenderWindow *window;
        level_t **levels;
        smenu_t *smenu;
        float volume;
        sfMusic *music;
        sfBool cutscenes;
        text_t text;
        sfClock *game_clock;
    } rpg_t;

    enum loops {MENU, GAME, SETTINGS};

    enum types {AIR, SLUG, SKELETON, MINIBOSS, BOSS};

    void open_close_events(rpg_t *rpg, sfEvent *event, sfRenderWindow *win);

#endif