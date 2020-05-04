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
    #include <time.h>
    #include "my.h"
    #include "particle.h"

    typedef struct image_s
    {
        sfSprite *sprite;
        sfTexture *texture;
    } image_t;

    typedef struct inventory_s
    {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        sfIntRect rect;
        int boulean_inv;
    } inventory_t;

    typedef struct merchant_s
    {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        sfIntRect rect;
    } merchant_t;

    typedef struct attack_s {
        sfClock *clock;
        particle_t particle[PARTICLE_MAX];
        particle_environment_t particle_environment;
        sfBool left_clicked;
        particle_t death[PARTICLE_MAX];
        particle_environment_t death_environment;
    } attack_t;

    typedef struct text_s
    {
        sfSprite *box_sprite;
        sfTexture *box_texture;
        sfText *stc;
        sfFont *font;
        sfVector2f pos;
    } text_t;

    typedef struct player_s
    {
        int hp;
        int damage;
        float speed;
        sfVector2f direction;
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
        int start_hp;
        int damage;
        float speed;
        float knockback;
        sfBool alive;
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect;
        int max;
        float fps;
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

    typedef struct bubble_s
    {
        sfTime time;
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        sfIntRect rect;
        sfClock *clock;
    } bubble_t;

    typedef struct object_s
    {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f size;
        sfVector2f pos;
        sfIntRect rect;
        int boulean;
    } object_t;


    typedef struct lama_s
    {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f size;
        sfVector2f pos;
    } lama_t;

    typedef struct smenu_s{
        sfRenderWindow *win;
        sfEvent event;
        text_t text;
        sfIntRect sprite_rect;
        sfSprite *bg_sprite;
        sfTexture *bg_texture;
        sfIntRect bg_rect;
        sfSprite *boat_sprite;
        sfTexture *boat_texture;
        sfIntRect boat_rect;
        button_t play_on;
        button_t play_off;
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
        button_t resume_on;
        button_t resume_off;
        button_t option_on;
        button_t option_off;
        sfClock *anim[2];
    } smenu_t;

    typedef struct rpg_s
    {
        image_t title;
        bool game_end;
        int scene;
        int prev_scene;
        int lvl;
        int xp;
        int mv[5];
        int potion;
        int boots;
        int shield;
        int check_item;
        int bool_npc;
        sfEvent event;
        player_t *player;
        sfRenderWindow *window;
        level_t **levels;
        smenu_t *smenu;
        float volume;
        sfMusic *music;
        sfBool cutscenes;
        text_t text;
        text_t htp;
        text_t stry;
        text_t end_screen;
        attack_t att;
        sfClock *game_clock;
        sfClock *en_clock[4];
        sfClock *boss_phases;
        inventory_t inv;
        merchant_t merchant;
        object_t potion_red;
        object_t potion_blue;
        object_t potion_yellow;
        object_t boots_1;
        object_t boots_2;
        object_t boots_3;
        object_t shield_1;
        object_t shield_2;
        object_t shield_3;
        text_t xp_box;
        text_t xp_text;
        text_t xp_nb;
        text_t box_info;
        text_t box_info_10;
        text_t box_info_15;
        sfClock *npc_clock;
        text_t text_npc;
        text_t text2_npc;
        merchant_t npc;
        bubble_t bubble;
        bubble_t box_npc;
        lama_t *softest;
        text_t hp_box;
        text_t hp_text;
        text_t hp_nb;
    } rpg_t;

    enum loops {MENU, GAME, SETTINGS, INVENTORY, MERCHANT, PAUSE, HTP, END, NPC};

    enum types {BAT, SLUG, EGG, MINIBOSS, BOSS};

#endif