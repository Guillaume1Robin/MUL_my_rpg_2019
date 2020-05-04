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
    int init_rpg(rpg_t *rpg);
    int initialize_window(rpg_t *rpg);
    void init_text_box(text_t *, char *, sfVector2f pos, sfVector2f scale);
    int create(rpg_t *rpg);
    void creater(rpg_t *rpg);
    player_t *create_player(rpg_t *rpg);
    void get_level_sprites_from_name(level_t *level, const char *name);
    void get_level_sprites_from_id(level_t *level, int id);
    level_t **create_game_layout(const int nb_levels);
    sfBool get_bat_percs(enemy_t *enemy);
    sfBool get_slug_percs(enemy_t *enemy);
    sfBool get_egg_percs(enemy_t *enemy);
    sfBool get_miniboss_percs(enemy_t *enemy);
    sfBool get_boss_percs(enemy_t *enemy);
    void reset_game(rpg_t *rpg);

    /* Menu */
    // init

    smenu_t *create_menu(void);
    int create_sprite_potion_blue(rpg_t *rpg);
    int create_softest(rpg_t *rpg);
    int create_sprite_option_off(smenu_t *sm);
    int create_sprite_option_button_on(smenu_t *sm);
    int create_sprite_resume_off(smenu_t *sm);
    int create_sprite_resume_button_on(smenu_t *sm);
    int create_sprite_button_play_on(smenu_t *smenu);
    int create_sprite_play_off(smenu_t *smenu);
    int create_sprite_button_htp_on(smenu_t *smenu);
    int create_sprite_htp_off(smenu_t *smenu);
    int create_sprite_button_quit_on(smenu_t *smenu);
    int create_sprite_quit_off(smenu_t *smenu);
    int create_sprite_button_setting_on(smenu_t *sm);
    int create_sprite_setting_off(smenu_t *sm);
    int create_sprite_back_pause_menu(smenu_t *sm);
    int create_sprite_button_plus_on(smenu_t *sm);
    int create_sprite_plus_off(smenu_t *sm);
    int create_sprite_button_less_on(smenu_t *sm);
    int create_sprite_less_off(smenu_t *sm);
    void init_button_return(smenu_t *sm);
    int create_sprite_potion_red(rpg_t *rpg);
    sfIntRect init_rect(smenu_t *smenu);
    void resize_window(rpg_t *rpg);
    void create_sprite_inventory(rpg_t *rpg);
    void close_merchant(rpg_t *rpg);
    void open_merchant(rpg_t *rpg);
    void create_sprite_merchant(rpg_t *rpg);
    void close_inventory(rpg_t *rpg);
    void open_inventory(rpg_t *rpg);
    char *htp_text(int which);
    void scene(rpg_t *rpg);
    int create_sprite_potion_yellow(rpg_t *rpg);
    int create_sprite_boots_1(rpg_t *rpg);
    int create_sprite_boots_2(rpg_t *rpg);
    int create_sprite_boots_3(rpg_t *rpg);
    int create_sprite_shield_1(rpg_t *rpg);
    int create_sprite_shield_2(rpg_t *rpg);
    int create_sprite_shield_3(rpg_t *rpg);
    void create_box_xp(rpg_t *rpg);
    void create_text_xp(rpg_t *rpg);
    void create_nb_xp(rpg_t *rpg);
    void create_box_xp_informations(rpg_t *rpg);
    void create_text_need_xp(rpg_t *rpg);
    void create_text_need_xp_10(rpg_t *rpg);
    void create_text_need_xp_15(rpg_t *rpg);
    void create_objects_sprites(rpg_t *rpg);
    int create_npc(rpg_t *rpg);
    void create_text_npc(rpg_t *rpg);
    void create_text_npc2(rpg_t *rpg);
    int create_sprite_bubble(rpg_t *rpg);
    int create_box_npc(rpg_t *rpg);
    void create_box_hp(rpg_t *rpg);
    void create_text_hp(rpg_t *rpg);
    void create_nb_hp(rpg_t *rpg);

    //update

    void update_potion_blue(rpg_t *rpg);
    void update_potion_red(rpg_t *rpg);
    void update_button_option(smenu_t *sm, rpg_t *rpg);
    void update_button_resume(smenu_t *sm, rpg_t *rpg);
    void menu_pause_loop(rpg_t *rpg);
    void update_option_button(smenu_t *sm, rpg_t *rpg);
    void update_resume_button(smenu_t *sm, rpg_t *rpg);
    void pause_menu_loop(rpg_t *rpg);
    void end_loop(rpg_t *rpg);
    void menu_loop(rpg_t *rpg);
    void settings_loop(rpg_t *rpg);
    void htp_loop(rpg_t *rpg);
    void inventory_loop(rpg_t *rpg);
    void merchant_loop(rpg_t *rpg);
    sfBool move_hrect(sfIntRect *rectangle, int offset, int max_value);
    sfBool move_vrect(sfIntRect *rectangle, int offset, int max_value);
    void update_button_play(smenu_t *smenu, rpg_t *rpg);
    void update_button_how_to_play(rpg_t *rpg);
    void update_button_quit(smenu_t *smenu);
    void update_button_setting(rpg_t *rpg);
    void update_button_plus(smenu_t *sm, rpg_t *rpg);
    void update_button_less(smenu_t *sm, rpg_t *rpg);
    void update_button_return(rpg_t *rpg);
    void update_animation(smenu_t *menu);
    void update_potion_yellow(rpg_t *rpg);
    void update_boots_1(rpg_t *rpg);
    void update_boots_2(rpg_t *rpg);
    void update_boots_3(rpg_t *rpg);
    void update_shield_1(rpg_t *rpg);
    void update_shield_2(rpg_t *rpg);
    void update_shield_3(rpg_t *rpg);
    void update_npc(rpg_t *rpg);
    void close_npc(rpg_t *rpg);
    void update_merchant(rpg_t *rpg);

    //display

    void draw_attacks(rpg_t *rpg);
    void display_button(smenu_t *smenu);
    void display_setting(smenu_t *smenu);
    void display_pause_button(smenu_t *smenu, rpg_t *rpg);
    void draw_text_box(sfRenderWindow *win, text_t text_box);
    void draw_boots(rpg_t *rpg);
    void draw_shield(rpg_t *rpg);
    void draw_informations(rpg_t *rpg);
    void draw_merchant(rpg_t *rpg);
    void draw_enemies(rpg_t *rpg);
    void display(rpg_t *rpg);
    void draw_npc(rpg_t *rpg);
    void draw_shield_inventory(rpg_t *rpg);
    void draw_boots_inventory(rpg_t *rpg);
    void draw_inventory(rpg_t *rpg);
    void draw_stat(rpg_t *rpg);

    /* Game */
    //player movement

    void set_movement(rpg_t *rpg);
    void move_player_up(rpg_t *rpg);
    void move_player_down(rpg_t *rpg);
    void move_player_left(rpg_t *rpg);
    void move_player_right(rpg_t *rpg);
    void stay_still(rpg_t *rpg);
    void follow_player(rpg_t *rpg, enemy_t *en);
    void collision_movement(rpg_t *rpg, enemy_t *en);
    void knockback(enemy_t *enemy, rpg_t *rpg, sfVector2f velocity);
    void coll_knockback(enemy_t *enemy, rpg_t *rpg, sfVector2f velocity);
    void upd_pos(rpg_t *rpg, sfVector2f *pos, \
    sfVector2f rect_pts[4], sfVector2f mv);

    //enemy movement

    void damage_player(rpg_t * rpg, enemy_t *en);
    void update_enemies(rpg_t *rpg);
    void boss_move(rpg_t *rpg, enemy_t *enemy);
    void enemy_collisions(rpg_t *rpg, sfVector2f *pos, sfVector2f velocity);

    //update

    void npc_loop(rpg_t *rpg);
    void main_loop(rpg_t *rpg);
    void game_loop(rpg_t *rpg);
    void clock_move_rect_player(rpg_t *rpg);
    void change_levels(rpg_t *rpg);
    void game_events(rpg_t *rpg);
    void update_game(rpg_t *rpg);
    void hp_enemies(rpg_t *rpg);
    void move_bubble(rpg_t *rpg);
    void move_rect(sfIntRect *rectangle, int offset, int max_value);
    enemy_t **load_enemies(FILE *file, int nb_en);

    //cutscenes

    void draw_all_map(rpg_t *rpg);
    void display(rpg_t *rpg);
    void play_cutscene(rpg_t *rpg);
    void cutscene_events(rpg_t *rpg);
    void start_text(rpg_t *rpg, float seconds);
    void end_text(rpg_t *rpg, float seconds);
    void final_text(rpg_t *rpg, float seconds);

    //music

    void init_music(rpg_t *rpg);
    void play_music(rpg_t *rpg);
    void change_volume(rpg_t *rpg);

    /* Destroy */

    void destroy_rpg(rpg_t *rpg);
    void destroy_levels(level_t **levels);

    /* Misc */

    sfVector2f vec_op(sfVector2f a, sfVector2f b, char op);
    sfVector2i to_ivec(sfVector2f vec);
    sfVector2f to_fvec(sfVector2i vec);
    sfBool intersec_rect_tri(sfVector2f tri[3], sfFloatRect rect);
    sfBool is_point_in_tri(sfVector2f pt, sfVector2f, sfVector2f, sfVector2f);
    float square_dist(sfVector2f a, sfVector2f b);

#endif