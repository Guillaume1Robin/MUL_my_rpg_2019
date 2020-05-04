/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** print_informations.c
*/

#include "rpg.h"

void create_box_xp_informations(rpg_t *rpg)
{
    char *name = "assets/sprites/text_box.png";

    rpg->box_info.box_texture = sfTexture_createFromFile(name, NULL);
    rpg->box_info.box_sprite = sfSprite_create();
    sfSprite_setTexture(rpg->box_info.box_sprite, \
    rpg->box_info.box_texture, sfTrue);
}

void create_text_need_xp(rpg_t *rpg)
{
    rpg->box_info.font = sfFont_createFromFile("assets/Pixellari.ttf");
    rpg->box_info.stc = sfText_create();
    sfText_setString(rpg->box_info.stc, "You need 5xp");
    sfText_setFont(rpg->box_info.stc, rpg->box_info.font);
    sfText_setColor(rpg->box_info.stc, sfBlack);
    sfText_setCharacterSize(rpg->box_info.stc, 30);
    rpg->box_info.pos.x = 1435;
    rpg->box_info.pos.y = 110;
    sfText_setPosition(rpg->box_info.stc, rpg->box_info.pos);
}

void create_text_need_xp_10(rpg_t *rpg)
{
    rpg->box_info_10.font = sfFont_createFromFile("assets/Pixellari.ttf");
    rpg->box_info_10.stc = sfText_create();
    sfText_setString(rpg->box_info_10.stc, "You need 10xp");
    sfText_setFont(rpg->box_info_10.stc, rpg->box_info_10.font);
    sfText_setColor(rpg->box_info_10.stc, sfBlack);
    sfText_setCharacterSize(rpg->box_info_10.stc, 30);
    rpg->box_info_10.pos.x = 1433;
    rpg->box_info_10.pos.y = 110;
    sfText_setPosition(rpg->box_info_10.stc, rpg->box_info_10.pos);
}

void create_text_need_xp_15(rpg_t *rpg)
{
    rpg->box_info_15.font = sfFont_createFromFile("assets/Pixellari.ttf");
    rpg->box_info_15.stc = sfText_create();
    sfText_setString(rpg->box_info_15.stc, "You need 15xp");
    sfText_setFont(rpg->box_info_15.stc, rpg->box_info_15.font);
    sfText_setColor(rpg->box_info_15.stc, sfBlack);
    sfText_setCharacterSize(rpg->box_info_15.stc, 30);
    rpg->box_info_15.pos.x = 1433;
    rpg->box_info_15.pos.y = 110;
    sfText_setPosition(rpg->box_info_15.stc, rpg->box_info_15.pos);
}