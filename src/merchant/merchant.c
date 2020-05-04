/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** merchant.c
*/

#include "rpg.h"

void create_sprite_merchant(rpg_t *rpg)
{
    char *name = "assets/sprites/inventaire.png";

    rpg->merchant.texture = sfTexture_createFromFile(name, NULL);
    rpg->merchant.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->merchant.sprite, rpg->merchant.texture, sfTrue);
    rpg->merchant.rect.top = 0;
    rpg->merchant.rect.left = 0;
    rpg->merchant.rect.width = 515;
    rpg->merchant.rect.height = 246;
    sfVector2f merchant_size = {2.0, 2.0};
    sfSprite_setScale(rpg->merchant.sprite, merchant_size);
}

void open_merchant(rpg_t *rpg)
{
    sfVector2f merch_pos = rpg->levels[rpg->lvl]->merch_pos;
    sfVector2f p_pos = rpg->player->pos;
    int key = sfKeySpace;

    if (rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == key\
     && square_dist(merch_pos, p_pos) < 2500)
        rpg->scene = MERCHANT;
}

void close_merchant(rpg_t *rpg)
{
    int ks = sfKeySpace;
    int kes = sfKeyEscape;
    if ((rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == ks)\
     || (rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == kes))
        rpg->scene = GAME;
}

void update_merchant(rpg_t *rpg)
{
    update_potion_red(rpg);
    update_potion_blue(rpg);
    update_potion_yellow(rpg);
    update_boots_1(rpg);
    update_boots_2(rpg);
    update_boots_3(rpg);
    update_shield_1(rpg);
    update_shield_2(rpg);
    update_shield_3(rpg);
}

void merchant_loop(rpg_t *rpg)
{
    level_t *curr_level = rpg->levels[rpg->lvl];

    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        if (rpg->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        close_merchant(rpg);
        update_merchant(rpg);
    }
    sfRenderWindow_clear(rpg->smenu->win, sfBlack);
    sfRenderWindow_drawSprite(rpg->window, curr_level->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->player->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, curr_level->ol_sprite, NULL);
    draw_all_map(rpg);
    sfRenderWindow_display(rpg->smenu->win);
}