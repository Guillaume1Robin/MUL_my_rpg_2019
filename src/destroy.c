/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy.c
*/

#include "rpg.h"

void destroy_image(sfSprite *sprite, sfTexture *texture)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void destroy_player(player_t *player)
{
    sfClock_destroy(player->clock);
    destroy_image(player->sprite, player->texture);
}

void destroy_menu(smenu_t *menu)
{
    destroy_image(menu->play_on.sprite, menu->play_on.texture);
    destroy_image(menu->play_off.sprite, menu->play_off.texture);
    destroy_image(menu->quit_on.sprite, menu->quit_on.texture);
    destroy_image(menu->quit_off.sprite, menu->quit_off.texture);
    destroy_image(menu->htp_on.sprite, menu->htp_on.texture);
    destroy_image(menu->htp_off.sprite, menu->htp_off.texture);
    destroy_image(menu->setting_on.sprite, menu->setting_on.texture);
    destroy_image(menu->setting_off.sprite, menu->setting_off.texture);
    destroy_image(menu->setting_back.sprite, menu->setting_back.texture);
    destroy_image(menu->plus_on.sprite, menu->plus_on.texture);
    destroy_image(menu->plus_off.sprite, menu->plus_off.texture);
    destroy_image(menu->less_on.sprite, menu->less_on.texture);
    destroy_image(menu->less_off.sprite, menu->less_off.texture);
    destroy_image(menu->bg_sprite, menu->bg_texture);
    destroy_image(menu->boat_sprite, menu->boat_texture);
}

void destroy_levels(level_t **levels)
{
    for (int i = 0; levels[i]; i++) {
        for (int en = 0; levels[i]->enemies[en]; en++) {
            sfSprite_destroy(levels[i]->enemies[en]->sprite);
            sfTexture_destroy(levels[i]->enemies[en]->texture);
            free(levels[i]->enemies[en]);
        }
        free(levels[i]->enemies);
        for (int col = 0; levels[i]->collisions[col]; col++)
            free(levels[i]->collisions[col]);
        free(levels[i]->collisions);
        destroy_image(levels[i]->sprite, levels[i]->texture);
        destroy_image(levels[i]->ol_sprite, levels[i]->ol_texture);
    }
    free(levels);
}

void destroy_rpg(rpg_t *rpg)
{
    write(2, "Destroying everything...\n", 25);
    sfRectangleShape_destroy(rpg->att.particle_environment.shape);
    destroy_player(rpg->player);
    destroy_image(rpg->title.sprite, rpg->title.texture);
    destroy_menu(rpg->smenu);
    destroy_levels(rpg->levels);
    sfMusic_destroy(rpg->music);
    sfRenderWindow_destroy(rpg->window);
    write(2, "All done!\nBye!\n", 10);
}
