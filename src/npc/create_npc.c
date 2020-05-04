/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_npc.c
*/

#include "rpg.h"

int create_npc(rpg_t *rpg)
{
    char *name = "assets/sprites/lama_npc.png";

    rpg->npc.texture = sfTexture_createFromFile(name, NULL);
    if (!rpg->npc.texture) {
        write(1, "error missing the button\n", 26);
        return (84);
    }
    rpg->npc.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->npc.sprite, rpg->npc.texture, sfTrue);
    rpg->npc.pos.x = 1000;
    rpg->npc.pos.y = 220;
    sfSprite_setPosition(rpg->npc.sprite, rpg->npc.pos);
    rpg->npc.rect.top = 0;
    rpg->npc.rect.left = 0;
    rpg->npc.rect.width = 56;
    rpg->npc.rect.height = 85;
    sfSprite_setTextureRect(rpg->npc.sprite, rpg->npc.rect);
    return (0);
}

void create_text_npc(rpg_t *rpg)
{
    char *text = "Hey! \nYou'll need some equipment for your quest! \
\nApproach the cup and press space!";

    rpg->text_npc.font = sfFont_createFromFile("assets/Pixellari.ttf");
    rpg->text_npc.stc = sfText_create();
    sfText_setString(rpg->text_npc.stc, text);
    sfText_setFont(rpg->text_npc.stc, rpg->text_npc.font);
    sfText_setColor(rpg->text_npc.stc, sfBlack);
    sfText_setCharacterSize(rpg->text_npc.stc, 35);
    rpg->text_npc.pos.x = 580;
    rpg->text_npc.pos.y = 830;
    sfText_setPosition(rpg->text_npc.stc, rpg->text_npc.pos);
}

void create_text_npc2(rpg_t *rpg)
{
    char *text = "You can buy as many as you wish,\n\
you just need to let them refurnish!\nGood luck!";

    rpg->text2_npc.font = sfFont_createFromFile("assets/Pixellari.ttf");
    rpg->text2_npc.stc = sfText_create();
    sfText_setString(rpg->text2_npc.stc, text);
    sfText_setFont(rpg->text2_npc.stc, rpg->text2_npc.font);
    sfText_setColor(rpg->text2_npc.stc, sfBlack);
    sfText_setCharacterSize(rpg->text2_npc.stc, 35);
    rpg->text2_npc.pos.x = 580;
    rpg->text2_npc.pos.y = 830;
    sfText_setPosition(rpg->text2_npc.stc, rpg->text2_npc.pos);
}

void create_bow_npc_two(rpg_t *rpg)
{
    rpg->box_npc.rect.top = 0;
    rpg->box_npc.rect.left = 0;
    rpg->box_npc.rect.width = 256;
    rpg->box_npc.rect.height = 64;
    sfSprite_setTextureRect(rpg->box_npc.sprite, rpg->box_npc.rect);
}

int create_box_npc(rpg_t *rpg)
{
    char *name = "assets/sprites/text_box.png";

    rpg->box_npc.texture = sfTexture_createFromFile(name, NULL);
    if (!rpg->box_npc.texture) {
        write(1, "error missing the button\n", 26);
        return (84);
    }
    rpg->box_npc.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->box_npc.sprite, rpg->box_npc.texture, sfTrue);
    rpg->box_npc.pos.x = 550;
    rpg->box_npc.pos.y = 800;
    sfSprite_setPosition(rpg->box_npc.sprite, rpg->box_npc.pos);
    sfVector2f box_npc_size = {3.0, 3.0};
    sfSprite_setScale(rpg->box_npc.sprite, box_npc_size);
    create_bow_npc_two(rpg);
    return (0);
}