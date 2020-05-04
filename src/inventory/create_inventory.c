/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_inventory.c
*/

#include "rpg.h"

void create_sprite_inventory(rpg_t *rpg)
{
    char *name = "assets/sprites/inventaire1.png";

    rpg->inv.texture = sfTexture_createFromFile(name, NULL);
    rpg->inv.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->inv.sprite, rpg->inv.texture, sfTrue);
    rpg->inv.rect.top = 0;
    rpg->inv.rect.left = 0;
    rpg->inv.rect.width = 515;
    rpg->inv.rect.height = 246;
    sfVector2f inv_size = {2.0, 2.0};
    sfSprite_setScale(rpg->inv.sprite, inv_size);
}

void open_inventory(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyI))
        rpg->scene = INVENTORY;
}

void close_inventory(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyI))
        rpg->scene = GAME;
}

void create_objects_sprites(rpg_t *rpg)
{
    create_box_xp(rpg);
    create_sprite_potion_red(rpg);
    create_sprite_potion_blue(rpg);
    create_sprite_potion_yellow(rpg);
    create_sprite_boots_1(rpg);
    create_sprite_boots_2(rpg);
    create_sprite_boots_3(rpg);
    create_sprite_shield_1(rpg);
    create_sprite_shield_2(rpg);
    create_sprite_shield_3(rpg);
    create_text_xp(rpg);
    create_nb_xp(rpg);
    create_box_xp_informations(rpg);
    create_text_need_xp_10(rpg);
    create_text_need_xp_15(rpg);
    create_text_need_xp(rpg);
    create_npc(rpg);
    create_text_npc(rpg);
    create_text_npc2(rpg);
    create_sprite_bubble(rpg);
    create_box_npc(rpg);
}

void inventory_loop(rpg_t *rpg)
{
    level_t *curr_level = rpg->levels[rpg->lvl];

    while (sfRenderWindow_pollEvent(rpg->window, &rpg->smenu->event)) {
        if (rpg->event.type == sfEvtClosed) {
            sfRenderWindow_close(rpg->window);
        }
        close_inventory(rpg);
    }
    sfRenderWindow_clear(rpg->smenu->win, sfBlack);
    sfRenderWindow_drawSprite(rpg->window, curr_level->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->player->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, curr_level->ol_sprite, NULL);
    if (rpg->lvl == 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->npc.sprite, NULL);
    draw_stat(rpg);
    draw_inventory(rpg);
    draw_boots_inventory(rpg);
    draw_shield_inventory(rpg);
    sfRenderWindow_display(rpg->smenu->win);
}