/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** start_menu_two.c
*/

#include "rpg.h"

void set_menu_booleans(smenu_t *smenu)
{
    smenu->play_off.boulean_button = 0;
    smenu->htp_off.boulean_button = 0;
    smenu->quit_off.boulean_button = 0;
    smenu->setting_off.boulean_button = 0;
    smenu->plus_off.boulean_button = 0;
    smenu->less_off.boulean_button = 0;
    smenu->play_on.boulean_button = 0;
    smenu->htp_on.boulean_button = 0;
    smenu->quit_on.boulean_button = 0;
    smenu->setting_on.boulean_button = 0;
    smenu->plus_on.boulean_button = 0;
    smenu->less_on.boulean_button = 0;
}

void init_animation(smenu_t *smenu)
{
    smenu->anim[0] = sfClock_create();
    smenu->anim[1] = sfClock_create();
    smenu->boat_sprite = sfSprite_create();
    sfSprite_setScale(smenu->boat_sprite, (sfVector2f){6, 6});
    smenu->boat_texture = sfTexture_createFromFile("assets/sprites/lama_\
boat.png", NULL);
    smenu->boat_rect = (sfIntRect){0, 0, 341, 192};
    sfSprite_setTexture(smenu->boat_sprite, smenu->boat_texture, sfTrue);
    sfSprite_setTextureRect(smenu->boat_sprite, smenu->boat_rect);
    sfSprite_setPosition(smenu->boat_sprite, (sfVector2f){0, 0});
    smenu->bg_sprite = sfSprite_create();
    sfSprite_setScale(smenu->bg_sprite, (sfVector2f){6, 6});
    smenu->bg_texture = sfTexture_createFromFile("assets/sprites/\
background.png", NULL);
    smenu->bg_rect = smenu->boat_rect;
    sfSprite_setTexture(smenu->bg_sprite, smenu->bg_texture, sfTrue);
    sfSprite_setTextureRect(smenu->bg_sprite, smenu->bg_rect);
    sfSprite_setPosition(smenu->bg_sprite, (sfVector2f){0, 0});
}

void create_sprites_menu(smenu_t *smenu)
{
    create_sprite_button_play_on(smenu);
    create_sprite_play_off(smenu);
    create_sprite_button_htp_on(smenu);
    create_sprite_htp_off(smenu);
    create_sprite_button_quit_on(smenu);
    create_sprite_quit_off(smenu);
    create_sprite_button_setting_on(smenu);
    create_sprite_setting_off(smenu);
    create_sprite_back_pause_menu(smenu);
    create_sprite_button_plus_on(smenu);
    create_sprite_plus_off(smenu);
    create_sprite_button_less_on(smenu);
    create_sprite_less_off(smenu);
    create_sprite_resume_button_on(smenu);
    create_sprite_resume_off(smenu);
    create_sprite_option_button_on(smenu);
    create_sprite_option_off(smenu);
}

smenu_t *create_menu(void)
{
    smenu_t *smenu = malloc(sizeof(smenu_t));
    sfVector2f pos = (sfVector2f){600, 300};

    init_animation(smenu);
    init_text_box(&smenu->text, "Volume", pos, (sfVector2f){2, 1});
    create_sprites_menu(smenu);
    return (smenu);
}