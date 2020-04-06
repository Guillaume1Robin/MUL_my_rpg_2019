/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** prototypes.h
*/

#ifndef PROTOTYPES_H_
    #define PROTOTYPES_H_

    #include "basic.h"

    /* Initiate the program */
    int initialise_value_struct(rpg_t *rpg);
    void create(rpg_t *rpg);
    int create_window(rpg_t *rpg);
    int create_map(rpg_t *rpg);
    int create_player(rpg_t *rpg);

    /* Menu */
    // init

    smenu_t *create_menu(void);
    void create_parallax(smenu_t *smenu);
    int create_sprite_button_play_on(smenu_t *smenu);
    int create_sprite_play_off(smenu_t *smenu);
    int create_sprite_button_save_on(smenu_t *smenu);
    int create_sprite_save_off(smenu_t *smenu);
    int create_sprite_button_htp_on(smenu_t *smenu);
    int create_sprite_htp_off(smenu_t *smenu);
    int create_sprite_button_quit_on(smenu_t *smenu);
    int create_sprite_quit_off(smenu_t *smenu);
    sfIntRect init_rect(smenu_t *smenu);

    //update

    void menu_loop(rpg_t *rpg);
    void move_parallax(smenu_t *smenu);
    void move_hrect(sfIntRect *rectangle, int offset, int max_value);
    void move_vrect(sfIntRect *rectangle, int offset, int max_value);
    void update_button_play(smenu_t *smenu, rpg_t *rpg);
    void update_button_save(smenu_t *smenu);
    void update_button_how_to_play(smenu_t *smenu);
    void update_button_quit(smenu_t *smenu);

    //display

    void display_button(smenu_t *smenu);
    void draw_parallax(smenu_t *smenu);

    /* Game */
    //player movement

    void set_movement(rpg_t *rpg);
    void move_player_up(rpg_t *rpg);
    void move_player_down(rpg_t *rpg);
    void move_player_left(rpg_t *rpg);
    void move_player_right(rpg_t *rpg);
    void stay_still(rpg_t *rpg);

    //update

    void main_loop(rpg_t *rpg);
    void game_loop(rpg_t *rpg);
    void clock_move_rect_player(rpg_t *rpg);

    //display

    void display(rpg_t *rpg);

    /* Destroy */

#endif