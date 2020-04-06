/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** rpg.h
*/

#ifndef START_MENU_H_
    #define START_MENU_H_

    #include "basic.h"

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
        sfBool bool;
    } smenu_t;

    //menu_principal.c
    void menu_loop(smenu_t *smenu);
    void create_parallax(smenu_t *smenu);
    void draw_parallax(smenu_t *smenu);
    smenu_t *create_menu(void);
    void display_button(smenu_t *smenu);

    // move_parallax.c
    void move_parallax(smenu_t *smenu);
    void move_hrect(sfIntRect *rectangle, int offset, int max_value);
    void move_vrect(sfIntRect *rectangle, int offset, int max_value);
    sfIntRect init_rect(smenu_t *smenu);

    //create_parallax.c
    void create_parallax(smenu_t *smenu);
    void draw_parallax(smenu_t *smenu);

    //button_play.c
    int create_sprite_button_play_on(smenu_t *smenu);
    void init_button_play(smenu_t *smenu);
    int create_sprite_play_off(smenu_t *smenu);

    //button_save.c
    int create_sprite_button_save_on(smenu_t *smenu);
    int create_sprite_save_off(smenu_t *smenu);
    void init_button_save(smenu_t *smenu);

    //button_how_to_play.c
    int create_sprite_button_htp_on(smenu_t *smenu);
    int create_sprite_htp_off(smenu_t *smenu);
    void init_button_how_to_play(smenu_t *smenu);

    //button_quit.c
    int create_sprite_button_quit_on(smenu_t *smenu);
    int create_sprite_quit_off(smenu_t *smenu);
    void init_button_quit(smenu_t *smenu);

#endif