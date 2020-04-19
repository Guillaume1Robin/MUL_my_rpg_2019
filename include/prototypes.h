/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** prototypes.h
*/

#ifndef PROTOTYPES_H_
    #define PROTOTYPES_H_

    #include "basic.h"

    /* Parser */
    int **collision_parser(char const *map_path);
    int **fcollision_parser(FILE *file);
    sfBool wrong_line_test(char **sline, char *line);
    level_t *level_parser(char const *level_path);

    /* Initiate the program */
    int initialize_value_struct(rpg_t *rpg);
    int initialize_window(rpg_t *rpg);
    void create(rpg_t *rpg);
    int create_window(rpg_t *rpg);
    int create_player(rpg_t *rpg);
    void get_level_sprites_from_name(level_t *level, const char *name);
    void get_level_sprites_from_id(level_t *level, int id);
    level_t **create_game_layout(const int nb_levels);
    sfBool get_bat_percs(enemy_t *enemy);
    sfBool get_slug_percs(enemy_t *enemy);
    sfBool get_skeleton_percs(enemy_t *enemy);
    sfBool get_miniboss_percs(enemy_t *enemy);
    sfBool get_boss_percs(enemy_t *enemy);

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
    int create_sprite_button_setting_on(smenu_t *sm);
    int create_sprite_setting_off(smenu_t *sm);
    int create_sprite_back_menu_pause(smenu_t *sm);
    int create_sprite_button_plus_on(smenu_t *sm);
    int create_sprite_plus_off(smenu_t *sm);
    int create_sprite_button_less_on(smenu_t *sm);
    int create_sprite_less_off(smenu_t *sm);
    void init_button_return(smenu_t *sm);
    sfIntRect init_rect(smenu_t *smenu);
    void resize_window(rpg_t *rpg);

    //update

    void menu_loop(rpg_t *rpg);
    void settings_loop(rpg_t *rpg);
    void move_parallax(smenu_t *smenu);
    void move_hrect(sfIntRect *rectangle, int offset, int max_value);
    void move_vrect(sfIntRect *rectangle, int offset, int max_value);
    void update_button_play(smenu_t *smenu, rpg_t *rpg);
    void update_button_save(smenu_t *smenu);
    void update_button_how_to_play(smenu_t *smenu);
    void update_button_quit(rpg_t *rpg, smenu_t *smenu);
    void update_button_setting(rpg_t *rpg);
    void update_button_plus(smenu_t *sm, rpg_t *rpg);
    void update_button_less(smenu_t *sm, rpg_t *rpg);
    void update_button_return(rpg_t *rpg);


    //display

    void display_button(smenu_t *smenu);
    void draw_parallax(smenu_t *smenu);
    void display_setting(smenu_t *smenu);


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
    void change_levels(rpg_t *rpg);

    //display

    void display(rpg_t *rpg);
    void play_cutscene(rpg_t *rpg);

    //music

    void init_music(rpg_t *rpg);
    void play_music(rpg_t *rpg);
    void change_volume(rpg_t *rpg);

    /* Destroy */

    void destroy_rpg(rpg_t *rpg);

#endif