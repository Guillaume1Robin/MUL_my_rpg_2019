/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** print_hp.c
*/

#include "rpg.h"

void create_box_hp(rpg_t *rpg)
{
    char *name = "assets/sprites/text_box.png";

    rpg->hp_box.box_texture = sfTexture_createFromFile(name, NULL);
    rpg->hp_box.box_sprite = sfSprite_create();
    sfSprite_setTexture(rpg->hp_box.box_sprite, \
    rpg->hp_box.box_texture, sfTrue);
    rpg->hp_box.pos.x = 1650;
    rpg->hp_box.pos.y = 75;
    sfSprite_setPosition(rpg->hp_box.box_sprite, rpg->hp_box.pos);
}

void create_text_hp(rpg_t *rpg)
{
    rpg->hp_text.font = sfFont_createFromFile("assets/Pixellari.ttf");
    rpg->hp_text.stc = sfText_create();
    sfText_setString(rpg->hp_text.stc, "HP");
    sfText_setFont(rpg->hp_text.stc, rpg->hp_text.font);
    sfText_setColor(rpg->hp_text.stc, sfBlack);
    sfText_setCharacterSize(rpg->hp_text.stc, 60);
    rpg->hp_text.pos.x = 1670;
    rpg->hp_text.pos.y = 70;
    sfText_setPosition(rpg->hp_text.stc, rpg->hp_text.pos);
}

void create_nb_hp(rpg_t *rpg)
{
    rpg->hp_nb.font = sfFont_createFromFile("assets/Pixellari.ttf");
    rpg->hp_nb.stc = sfText_create();
    sfText_setFont(rpg->hp_nb.stc, rpg->hp_nb.font);
    sfText_setColor(rpg->hp_nb.stc, sfBlack);
    sfText_setCharacterSize(rpg->hp_nb.stc, 60);
    rpg->hp_nb.pos.x = 1760;
    rpg->hp_nb.pos.y = 70;
    sfText_setPosition(rpg->hp_nb.stc, rpg->hp_nb.pos);
}