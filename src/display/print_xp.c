/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** print_xp.c
*/

#include "rpg.h"

void create_box_xp(rpg_t *rpg)
{
    char *name = "assets/sprites/text_box.png";

    rpg->xp_box.box_texture = sfTexture_createFromFile(name, NULL);
    rpg->xp_box.box_sprite = sfSprite_create();
    sfSprite_setTexture(rpg->xp_box.box_sprite, \
    rpg->xp_box.box_texture, sfTrue);
    rpg->xp_box.pos.x = 1650;
    rpg->xp_box.pos.y = 5;
    sfSprite_setPosition(rpg->xp_box.box_sprite, rpg->xp_box.pos);
}

void create_text_xp(rpg_t *rpg)
{
    rpg->xp_text.font = sfFont_createFromFile("assets/Pixellari.ttf");
    rpg->xp_text.stc = sfText_create();
    sfText_setString(rpg->xp_text.stc, "XP");
    sfText_setFont(rpg->xp_text.stc, rpg->xp_text.font);
    sfText_setColor(rpg->xp_text.stc, sfBlack);
    sfText_setCharacterSize(rpg->xp_text.stc, 60);
    rpg->xp_text.pos.x = 1670;
    rpg->xp_text.pos.y = 0;
    sfText_setPosition(rpg->xp_text.stc, rpg->xp_text.pos);
}

void create_nb_xp(rpg_t *rpg)
{
    rpg->xp_nb.font = sfFont_createFromFile("assets/Pixellari.ttf");
    rpg->xp_nb.stc = sfText_create();
    sfText_setFont(rpg->xp_nb.stc, rpg->xp_nb.font);
    sfText_setColor(rpg->xp_nb.stc, sfBlack);
    sfText_setCharacterSize(rpg->xp_nb.stc, 60);
    rpg->xp_nb.pos.x = 1760;
    rpg->xp_nb.pos.y = 0;
    sfText_setPosition(rpg->xp_nb.stc, rpg->xp_nb.pos);
}
